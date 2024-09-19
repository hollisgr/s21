/**
 * @file frontend.h
 * @brief Prototypes for functions of frontend logic
 * @details
 * @author hollisgr / S21
 * @date 10.07.2024
 *
 */

#ifndef FRONTEND_H
#define FRONTEND_H

#include "defines.h"
#include "objects.h"
#include "tetris.h"

void print_overlay(figure_t figure, Game_state state);
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void print_stats(game_stats_t *stats);
void print_current_figure(figure_t *figure, map_t *map);
void print_collision(map_t map);
void print_intro_massage();
void print_tips();

#endif