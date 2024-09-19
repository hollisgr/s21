/**
 * @file fsm.c
 * @brief Implemetation of finite state machine (FSM)
 * @details
 * @author hollisgr / S21
 * @date 10.07.2024
 *
 */

#include "tetris.h"

UserAction_t get_signal(int user_input) {
  UserAction_t rc;

  if (user_input == KEY_UP)
    rc = Up;
  else if (user_input == KEY_DOWN)
    rc = Down;
  else if (user_input == KEY_LEFT)
    rc = Left;
  else if (user_input == KEY_RIGHT)
    rc = Right;
  else if (user_input == ' ')
    rc = Action;
  else if (user_input == 'q')
    rc = Terminate;
  else if (user_input == 'p')
    rc = Pause;
  else if (user_input == ENTER_KEY)
    rc = Start;

  return rc;
}

void sigact(UserAction_t signal, Game_state *state, figure_t *figure,
            figure_t *next_figure, map_t *map, game_stats_t *stats) {
  if (*state != START) print_stats(stats);
  switch (*state) {
    case START:
      print_intro_massage();
      switch (signal) {
        case Start:
          wclear(stdscr);
          *state = MOVING;
          break;
        case Terminate:
          *state = EXIT_STATE;
          break;
        default:
          *state = START;
          break;
      }
      break;
    case COLLIDE:
      attach_figure_to_collision(*figure, map);
      *state = SPAWN;
      break;
    case SPAWN:
      print_current_figure(figure, map);
      if (!check_collision(1, 9, *figure, map)) {
        *state = MOVING;
      } else
        *state = GAMEOVER;
      break;
    case MOVING:
      switch (signal) {
        case Down:
          move_figure_to_ground(figure, map);
          *state = COLLIDE;
          break;
        case Right:
          move_figure_right(figure, map);
          break;
        case Left:
          move_figure_left(figure, map);
          break;
        case Action:
          rotate_figure(figure, map);
          break;
        case Terminate:
          *state = EXIT_STATE;
          break;
        default:
          break;
      }
      break;
    case SHIFTING:
      *state = MOVING;
      break;
    case PAUSE:
      switch (signal) {
        case Pause:
          *state = MOVING;
          break;
        default:
          break;
      }
      break;
    case GAMEOVER:
      mvprintw(25, 5, "GAME OVER! PRESS Q TO QUIT");
      switch (signal) {
        case Terminate:
          *state = EXIT_STATE;
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
  if (*state != START) {
    print_collision(*map);
    print_current_figure(figure, map);
    print_overlay(*next_figure, *state);
  }
  is_filled(stats, map);
}

void game_loop(Game_state state) {
  int input = 0;
  int break_flag = 1;
  int pause_flag = 1;
  int tips_flag = 1;
  figure_t figure;
  figure_t next_figure;
  map_t map;
  game_stats_t stats;
  // Game_state state = START;
  UserAction_t signal;
  init_game(&stats, &map, &figure, &next_figure);
  while (break_flag) {
    signal = get_signal(input);
    sigact(signal, &state, &figure, &next_figure, &map, &stats);
    if (state == EXIT_STATE) break_flag = 0;
    if (input == 'p' && pause_flag) {
      state = PAUSE;
      pause_flag = 0;
    }
    if (input == KEY_F(1) && tips_flag) {
      print_tips();
      tips_flag = 0;
    }
    if (state != SPAWN) input = GET_USER_INPUT;
    if (state == MOVING) {
      updateCurrentState(&figure, &map, &stats, &state);
      pause_flag = 1;
      tips_flag = 1;
    }
    if (state == SPAWN) {
      figure = next_figure;
      init_figure(&next_figure);
    }
  }
}
