/**
 * @file frontend.c
 * @brief Implemetation of terminal interface
 * @details
 * @author hollisgr / S21
 * @date 10.07.2024
 *
 */

#include "tetris.h"

void print_overlay(figure_t figure, Game_state state) {
  // рамка игрового поля
  print_rectangle(0, BOARD_N + 1, 0, BOARD_M + 1);

  // рамка поля со статистикой
  print_rectangle(0, BOARD_N + 1, BOARD_M + 2, BOARD_M + HUD_WIDTH + 3);

  // рамка LEVEL
  print_rectangle(2, 4, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);

  // рамка SCORE
  print_rectangle(6, 8, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);

  // РАМКА HI-SCORE
  print_rectangle(10, 12, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);

  // рамка NEXT
  print_rectangle(14, 19, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);

  MVPRINTW(1, BOARD_M + 5, "LEVEL");
  MVPRINTW(5, BOARD_M + 5, "SCORE");
  MVPRINTW(9, BOARD_M + 5, "HI-SCORE");
  MVPRINTW(13, BOARD_M + 5, "NEXT");

  // отрисовка следующей фигуры
  for (int i = 0; i < FIGURE_SIZE - 1; i++) {
    int temp_x = 24;
    int temp_y = 15;
    for (int j = 0; j < FIGURE_SIZE; j++) {
      PRINT_CELL(temp_y + i, temp_x + j, PAIR_EMPTY);
      PRINT_CELL(temp_y + i, temp_x + j + 1, PAIR_EMPTY);
      temp_x++;
    }
  }

  for (int i = 0; i < FIGURE_SIZE; i++) {
    int temp_x = 24;
    int temp_y = 15;
    for (int j = 0; j < FIGURE_SIZE; j++) {
      int n = figure.cells[i][j];
      if (n != 0) {
        PRINT_CELL(temp_y + i, temp_x + j, n);
        PRINT_CELL(temp_y + i, temp_x + j + 1, n);
      }
      temp_x++;
    }
  }

  if (state == PAUSE) {
    mvprintw(12, 5, "GAME IS PAUSED!");
    mvprintw(13, 4, "PRESS P TO UNPAUSE");
  }

  if (state == START) mvprintw(12, 3, INTRO_MESSAGE);  // Prints welcome massage

  // заглушка над игровым полем и интерфейсом (чтоб фигуры над полем не
  // отрисовывались)
  for (int i = -5; i < 0; i++)
    for (int j = -1; j < BOARD_M + HUD_WIDTH; j++) MVADDCH(i, j, ' ');
}

// функция отрисовывает поле, y - высота поля, x - ширина поля
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x) {
  MVADDCH(top_y, left_x, ACS_ULCORNER);

  int i = left_x + 1;

  for (; i < right_x; i++) MVADDCH(top_y, i, ACS_HLINE);
  MVADDCH(top_y, i, ACS_URCORNER);

  for (int i = top_y + 1; i < bottom_y; i++) {
    MVADDCH(i, left_x, ACS_VLINE);
    MVADDCH(i, right_x, ACS_VLINE);
  }

  MVADDCH(bottom_y, left_x, ACS_LLCORNER);
  i = left_x + 1;
  for (; i < right_x; i++) MVADDCH(bottom_y, i, ACS_HLINE);
  MVADDCH(bottom_y, i, ACS_LRCORNER);
}

void print_stats(game_stats_t *stats) {
  MVPRINTW(3, BOARD_M + 12, "%d", stats->level);  // вывод счетчика уровня
  MVPRINTW(7, BOARD_M + 7, "%.6d", stats->score);  // вывод счетчика очков
  MVPRINTW(11, BOARD_M + 7, "%.6d", stats->hi_score);  // вывод макс. очков
}

void print_current_figure(figure_t *figure, map_t *map) {
  figure_t projection = *figure;
  int x = projection.x;
  clear_figure(map);

  //  отрисовка проекции фигуры
  while (!check_collision(projection.y, projection.x, projection, map))
    projection.y++;
  int proj_y = projection.y - 1;
  for (int i = 0; i < FIGURE_SIZE; i++) {
    x = projection.x;
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (projection.cells[i][j]) {
        map->current_figure[proj_y + i][x + j] = 9;
        map->current_figure[proj_y + i][x + j + 1] = 9;
      }
      x++;
    }
  }

  attach_current_figure(*figure, map);
  for (int i = 1; i < ROWS_MAP - 1; i++)
    for (int j = 1; j < COLS_MAP - 1; j++) {
      int n = map->current_figure[i][j];
      if (n > 0) {
        PRINT_CELL(i, j, n);
      }
    }
}

void print_collision(map_t map) {
  for (int i = 1; i < ROWS_MAP - 1; i++)
    for (int j = 1; j < COLS_MAP - 1; j++) {
      int n = map.collision[i][j];
      if (n != 0) {
        PRINT_CELL(i, j, n);
      } else {
        PRINT_CELL(i, j, PAIR_EMPTY);
      }
    }
}
