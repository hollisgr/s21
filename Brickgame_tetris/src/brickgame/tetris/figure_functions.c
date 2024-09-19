/**
 * @file figure_functions.c
 * @brief Implemetation of figure's logic
 * @details
 * @author hollisgr / S21
 * @date 10.07.2024
 *
 */

#include "tetris.h"

void init_figure(figure_t *figure) {
  char k;
  int n = rand();
  switch (n % 7) {
    case 0:
      k = 'o';
      break;
    case 1:
      k = 'i';
      break;
    case 2:
      k = 's';
      break;
    case 3:
      k = 'z';
      break;
    case 4:
      k = 't';
      break;
    case 5:
      k = 'l';
      break;
    case 6:
      k = 'j';
      break;
    default:
      break;
  }
  figure->type = k;
  figure->x = 9;
  figure->y = 1;
  init_figure_prototype(figure);
}

void init_figure_prototype(figure_t *figure) {
  int figure_i[FIGURE_SIZE][FIGURE_SIZE] = {{0, 0, 2, 0, 0},
                                            {0, 0, 2, 0, 0},
                                            {0, 0, 2, 0, 0},
                                            {0, 0, 2, 0, 0},
                                            {0, 0, 0, 0, 0}};

  int figure_o[FIGURE_SIZE][FIGURE_SIZE] = {{0, 0, 0, 0, 0},
                                            {0, 3, 3, 0, 0},
                                            {0, 3, 3, 0, 0},
                                            {0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0}};

  int figure_l[FIGURE_SIZE][FIGURE_SIZE] = {{0, 0, 0, 0, 0},
                                            {0, 0, 7, 0, 0},
                                            {0, 0, 7, 0, 0},
                                            {0, 0, 7, 7, 0},
                                            {0, 0, 0, 0, 0}};

  int figure_j[FIGURE_SIZE][FIGURE_SIZE] = {{0, 0, 0, 0, 0},
                                            {0, 0, 8, 0, 0},
                                            {0, 0, 8, 0, 0},
                                            {0, 8, 8, 0, 0},
                                            {0, 0, 0, 0, 0}};

  int figure_s[FIGURE_SIZE][FIGURE_SIZE] = {{0, 0, 0, 0, 0},
                                            {0, 0, 4, 4, 0},
                                            {0, 4, 4, 0, 0},
                                            {0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0}};

  int figure_z[FIGURE_SIZE][FIGURE_SIZE] = {{0, 0, 0, 0, 0},
                                            {0, 5, 5, 0, 0},
                                            {0, 0, 5, 5, 0},
                                            {0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0}};

  int figure_t[FIGURE_SIZE][FIGURE_SIZE] = {{0, 0, 0, 0, 0},
                                            {0, 0, 6, 0, 0},
                                            {0, 0, 6, 6, 0},
                                            {0, 0, 6, 0, 0},
                                            {0, 0, 0, 0, 0}};

  switch (figure->type) {
    case 'i':
      for (int i = 0; i < FIGURE_SIZE; i++)
        for (int j = 0; j < FIGURE_SIZE; j++)
          figure->cells[i][j] = figure_i[i][j];
      break;
    case 'o':
      for (int i = 0; i < FIGURE_SIZE; i++)
        for (int j = 0; j < FIGURE_SIZE; j++)
          figure->cells[i][j] = figure_o[i][j];
      break;
    case 'l':
      for (int i = 0; i < FIGURE_SIZE; i++)
        for (int j = 0; j < FIGURE_SIZE; j++)
          figure->cells[i][j] = figure_l[i][j];
      break;
    case 'j':
      for (int i = 0; i < FIGURE_SIZE; i++)
        for (int j = 0; j < FIGURE_SIZE; j++)
          figure->cells[i][j] = figure_j[i][j];
      break;
    case 's':
      for (int i = 0; i < FIGURE_SIZE; i++)
        for (int j = 0; j < FIGURE_SIZE; j++)
          figure->cells[i][j] = figure_s[i][j];
      break;
    case 'z':
      for (int i = 0; i < FIGURE_SIZE; i++)
        for (int j = 0; j < FIGURE_SIZE; j++)
          figure->cells[i][j] = figure_z[i][j];
      break;
    case 't':
      for (int i = 0; i < FIGURE_SIZE; i++)
        for (int j = 0; j < FIGURE_SIZE; j++)
          figure->cells[i][j] = figure_t[i][j];
      break;
    default:
      break;
  }
}

void move_figure_left(figure_t *figure, map_t *map) {
  int x = figure->x - 2;
  int y = figure->y;
  if (!check_collision(y, x, *figure, map)) {
    figure->x -= 2;
  }
}

void move_figure_right(figure_t *figure, map_t *map) {
  int x = figure->x + 2;
  int y = figure->y;
  if (!check_collision(y, x, *figure, map)) {
    figure->x += 2;
  }
}

int move_figure_down(figure_t *figure, map_t *map) {
  int code = 1;
  int x = figure->x;
  int y = figure->y + 1;
  if (!check_collision(y, x, *figure, map)) {
    figure->y += 1;
    code = 0;
  }
  return code;
}

void move_figure_to_ground(figure_t *figure, map_t *map) {
  int x = figure->x;
  int y = figure->y;
  while (!check_collision(y, x, *figure, map)) y++;
  figure->y = y - 1;
}

void rotate_figure(figure_t *figure, map_t *map) {
  if (figure->type == 'o') return;
  int temp_figure[FIGURE_SIZE][FIGURE_SIZE];
  int buffer_figure[FIGURE_SIZE][FIGURE_SIZE];
  int M = FIGURE_SIZE;
  int x = figure->x;
  int y = figure->y;
  // Запись во временную матрицу повернутых значений из матрицы фигуры
  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++) temp_figure[j][M - i - 1] = figure->cells[i][j];

  // Перезапись из временной матрицы повернутых значений в матрицу фигуры
  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++) {
      buffer_figure[i][j] = figure->cells[i][j];
      figure->cells[i][j] = temp_figure[i][j];
    }

  // Проверка коллизии, в случае неудачи замена на временную не повернутую
  // матрицу
  if (check_collision(y, x, *figure, map)) {
    for (int i = 0; i < M; i++)
      for (int j = 0; j < M; j++) figure->cells[i][j] = buffer_figure[i][j];
  } else {
    print_current_figure(figure, map);
  }
}

int check_collision(int y, int x, figure_t figure, map_t *map) {
  int code = 0;
  figure.x = x;
  figure.y = y;
  attach_current_figure(figure, map);
  for (int i = 0; i < ROWS_MAP; i++)
    for (int j = 0; j < COLS_MAP; j++) {
      int figure = map->current_figure[i][j];
      int collision = map->collision[i][j];
      if ((figure > 1) & (collision != 0)) {
        code = 1;
        break;
      }
    }
  clear_figure(map);
  return code;
}

void attach_figure_to_collision(figure_t figure, map_t *map) {
  int x = figure.x;
  int y = figure.y;
  for (int i = 0; i < FIGURE_SIZE; i++) {
    x = figure.x;
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (figure.cells[i][j]) {
        map->collision[y + i][x + j] = figure.cells[i][j];
        map->collision[y + i][x + j + 1] = figure.cells[i][j];
      }
      x++;
    }
  }
}

void attach_current_figure(figure_t figure, map_t *map) {
  int x = figure.x;
  int y = figure.y;
  int temp_x = x;
  for (int i = 0; i < FIGURE_SIZE; i++) {
    x = temp_x;
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (figure.cells[i][j] != 0) {
        map->current_figure[y + i][x + j] = figure.cells[i][j];
        map->current_figure[y + i][x + j + 1] = figure.cells[i][j];
      }
      x++;
    }
  }
}

void clear_figure(map_t *map) {
  for (int i = 0; i < ROWS_MAP; i++)
    for (int j = 0; j < COLS_MAP; j++) map->current_figure[i][j] = 1;
  for (int i = 0; i < ROWS_MAP - 1; i++)
    for (int j = 1; j < COLS_MAP - 1; j++) {
      map->current_figure[i][j] = 0;
    }
}

void is_filled(game_stats_t *stats, map_t *map) {
  int filled_counter = 0;
  for (int i = ROWS_MAP - 2; i > 1; i--) {
    filled_counter = 0;
    for (int j = 1; j < COLS_MAP - 1; j++) {
      if (map->collision[i][j] != 0) {
        filled_counter++;
      }
      if (filled_counter >= 20) {
        delete_filled(i, map);
        stats->score_multiplier++;
      }
    }
  }
}

void delete_filled(int i, map_t *map) {
  for (; i > 0; i--)
    for (int j = 1; j < COLS_MAP - 1; j++)
      map->collision[i][j] = map->collision[i - 1][j];
}