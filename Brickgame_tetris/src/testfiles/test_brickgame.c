#include "test_main.h"

START_TEST(tetris_1) {
  figure_t figure;
  figure_t next_figure;
  map_t map;
  game_stats_t stats;
  Game_state state = START;
  UserAction_t signal = Empty;
  int user_input = 1;
  init_game(&stats, &map, &figure, &next_figure);
  init_game(&stats, &map, &figure, &next_figure);
  init_game(&stats, &map, &figure, &next_figure);
  init_game(&stats, &map, &figure, &next_figure);
  init_game(&stats, &map, &figure, &next_figure);
  init_game(&stats, &map, &figure, &next_figure);
  init_game(&stats, &map, &figure, &next_figure);
  init_game(&stats, &map, &figure, &next_figure);
  init_game(&stats, &map, &figure, &next_figure);
  init_game(&stats, &map, &figure, &next_figure);
  init_game(&stats, &map, &figure, &next_figure);
  init_game(&stats, &map, &figure, &next_figure);
  stats.score_multiplier = 1;
  increase_points(&stats);
  stats.score_multiplier = 2;
  increase_points(&stats);
  stats.score_multiplier = 3;
  increase_points(&stats);
  stats.score_multiplier = 4;
  increase_points(&stats);
  move_figure_down(&figure, &map);
  move_figure_left(&figure, &map);
  move_figure_right(&figure, &map);
  move_figure_to_ground(&figure, &map);
  rotate_figure(&figure, &map);
  attach_figure_to_collision(figure, &map);
  is_filled(&stats, &map);
  delete_filled(1, &map);
  state = START;
  user_input = KEY_UP;
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);
  state = COLLIDE;
  user_input = KEY_DOWN;
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);
  state = MOVING;
  user_input = KEY_LEFT;
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);
  state = MOVING;

  user_input = KEY_DOWN;
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);
  state = MOVING;

  user_input = KEY_RIGHT;
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);
  state = MOVING;

  user_input = ' ';
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);
  state = MOVING;

  user_input = 'q';
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);

  state = SHIFTING;
  user_input = KEY_RIGHT;
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);
  state = PAUSE;
  user_input = ' ';
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);
  state = PAUSE;
  user_input = 'p';
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);
  state = GAMEOVER;
  user_input = 'q';
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);
  state = SPAWN;
  user_input = 'q';
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);
  user_input = ENTER_KEY;
  signal = get_signal(user_input);
  sigact(signal, &state, &figure, &next_figure, &map, &stats);

  updateCurrentState(&figure, &map, &stats, &state);
  stats.ticks_left = 0;
  updateCurrentState(&figure, &map, &stats, &state);
  state = EXIT_STATE;
  game_loop(state);
  print_tips();
}
END_TEST

Suite *test_tetris(void) {
  Suite *s = suite_create("s21_brickgame tetris");
  TCase *tc = tcase_create("tetris_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, tetris_1);
  // tcase_add_test(tc, tetris_2);
  // tcase_add_test(tc, tetris_3);
  // tcase_add_test(tc, tetris_4);
  // tcase_add_test(tc, tetris_5);
  // tcase_add_test(tc, tetris_6);
  // tcase_add_test(tc, tetris_7);
  // tcase_add_test(tc, tetris_8);
  // tcase_add_test(tc, tetris_9);
  // tcase_add_test(tc, tetris_10);
  // tcase_add_test(tc, tetris_11);
  return s;
}
