/**
 * @file backend.h
 * @brief Prototypes for functions of backend logic
 * @details
 * @author hollisgr / S21
 * @date 10.07.2024
 *
 */

#ifndef BACKEND_H
#define BACKEND_H

#include "defines.h"
#include "objects.h"
#include "tetris.h"

void init_game(game_stats_t *stats, map_t *map, figure_t *figure,
               figure_t *next_figure);
void init_colors();
void game_loop();
void init_stats(game_stats_t *stats);
void read_max_score(game_stats_t *stats);
void write_max_score(int score);
void updateCurrentState(figure_t *figure, map_t *map, game_stats_t *stats,
                        Game_state *state);
void is_filled(game_stats_t *stats, map_t *map);
void delete_filled(int i, map_t *map);
void increase_points(game_stats_t *stats);
void check_level(game_stats_t *stats);
void clear_figure(map_t *map);
void init_figure(figure_t *figure);
void init_figure_prototype(figure_t *figure);
void init_map(map_t *map);
void move_figure_left(figure_t *figure, map_t *map);
void move_figure_right(figure_t *figure, map_t *map);
void rotate_figure(figure_t *figure, map_t *map);
void move_figure_to_ground(figure_t *figure, map_t *map);
int move_figure_down(figure_t *figure, map_t *map);
void attach_figure_to_collision(figure_t figure, map_t *map);
void attach_current_figure(figure_t figure, map_t *map);
int check_collision(int y, int x, figure_t figure, map_t *map);
void sigact(UserAction_t signal, Game_state *state, figure_t *figure,
            figure_t *next_figure, map_t *map, game_stats_t *stats);
UserAction_t get_signal(int user_input);

#endif