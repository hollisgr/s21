/**
 * @file backend.c
 * @brief Implemetation of backend logic
 * @details
 * @author hollisgr / S21
 * @date 10.07.2024
 *
 */

#include "tetris.h"

/**
 * @brief Initialize main game structures
 * @return Have no return value
 * @param init_stats initialize game stats
 * @param init_map initialize map structures
 * @param init_colors initialize color pairs
 * @param init_figure initialize figure structure
 *
 */
void init_game(game_stats_t *stats, map_t *map, figure_t *figure,
               figure_t *next_figure) {
  init_stats(stats);
  init_map(map);
  init_colors();
  init_figure(figure);
  init_figure(next_figure);
}

/**
 * @brief Initialize stats
 * @return Have no return value
 */
void init_stats(game_stats_t *stats) {
  stats->level = 1;
  stats->level_buffer = 0;
  stats->score = 0;
  stats->score_multiplier = 0;
  stats->speed_multiplier = 0.3;
  stats->ticks = 5000;
  stats->ticks_left = stats->ticks;
  read_max_score(stats);
}

/**
 * @brief Initialize color pairs
 * @return Have no return value
 */
void init_colors() {
  start_color();
  init_pair(PAIR_FIGURE_I, COLOR_BLACK, COLOR_CYAN);
  init_pair(PAIR_FIGURE_O, COLOR_BLACK, 11);
  init_pair(PAIR_FIGURE_S, COLOR_BLACK, COLOR_RED);
  init_pair(PAIR_FIGURE_Z, COLOR_BLACK, COLOR_GREEN);
  init_pair(PAIR_FIGURE_T, COLOR_BLACK, COLOR_BLUE);
  init_pair(PAIR_FIGURE_L, COLOR_BLACK, COLOR_YELLOW);
  init_pair(PAIR_FIGURE_J, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(PAIR_EMPTY, COLOR_BLACK, COLOR_BLACK);
  init_pair(PAIR_PROJECTION, COLOR_BLACK, COLOR_WHITE);
}

/**
 * @brief Initialize map structures
 * @return Have no return value
 */
void init_map(map_t *map) {
  // заполнение всей матрицы единицами
  for (int i = 0; i < ROWS_MAP; i++)
    for (int j = 0; j < COLS_MAP; j++) {
      map->collision[i][j] = 1;
      map->current_figure[i][j] = 1;
    }

  // заполнение внутрянки матрицы нулями
  for (int i = 0; i < ROWS_MAP - 1; i++)
    for (int j = 1; j < COLS_MAP - 1; j++) {
      map->collision[i][j] = 0;
      map->current_figure[i][j] = 0;
    }
}

/**
 * @brief Increase current game score
 * @return Have no return value
 */
void increase_points(game_stats_t *stats) {
  switch (stats->score_multiplier) {
    case 1:
      stats->score_multiplier = 100;
      break;
    case 2:
      stats->score_multiplier = 300;
      break;
    case 3:
      stats->score_multiplier = 700;
      break;
    case 4:
      stats->score_multiplier = 1500;
    default:
      break;
  }
  if (stats->score_multiplier) {
    stats->score = stats->score + stats->score_multiplier;
    stats->level_buffer += stats->score_multiplier;
    stats->score_multiplier = 0;
  }
  check_level(stats);
}

/**
 * @brief Checking current level
 * @return Have no return value
 */
void check_level(game_stats_t *stats) {
  if (stats->level_buffer >= 600 && stats->level < 10) {
    stats->level++;
    stats->level_buffer = 0;
    stats->speed_multiplier += 0.2;
  }
}

/**
 * @brief Read max score from file stream
 * @return Have no return value
 */
void read_max_score(game_stats_t *stats) {
  FILE *fp;
  fp = fopen("game_stats.txt", "r+");
  fscanf(fp, "%d", &stats->hi_score);
  fclose(fp);
}

/**
 * @brief Write max score to file stream
 * @return Have no return value
 */
void write_max_score(int score) {
  FILE *fp;
  fp = fopen("game_stats.txt", "w");
  fprintf(fp, "%d", score);
  fclose(fp);
}

void updateCurrentState(figure_t *figure, map_t *map, game_stats_t *stats,
                        Game_state *state) {
  for (int i = 0; i < 1000; i++) {
    stats->ticks_left = stats->ticks_left - (stats->speed_multiplier * 1);
    if (stats->ticks_left <= 0) {
      stats->ticks_left = stats->ticks;
      increase_points(stats);
      if (stats->score > stats->hi_score) {
        write_max_score(stats->score);
        read_max_score(stats);
      }
      if (move_figure_down(figure, map)) {
        attach_figure_to_collision(*figure, map);
        *state = SPAWN;
      }
    }
  }
}