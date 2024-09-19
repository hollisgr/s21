/**
 * @file objects.h
 * @brief Prototypes of structures for library
 * @details
 * @author hollisgr / S21
 * @date 10.07.2024
 *
 */

#ifndef OBJECTS_H
#define OBJECTS_H

#include "tetris.h"

/**
 * @struct figure_t
 * @brief Struct for storage data of figures
 */
typedef struct {
  char type;                            ///< Type of figure
  int x;                                ///< Current figure's X-coordinate
  int y;                                ///< Current figure's Y-coordinate
  int cells[FIGURE_SIZE][FIGURE_SIZE];  ///< Array contains figures "cells"
} figure_t;

/**
 * @struct game_stats_t
 * @brief Struct for storage game's data
 */
typedef struct {
  int score;               ///< Current score
  int score_multiplier;    ///< Current score multiplier
  int level;               ///< Current level
  int level_buffer;        ///< Current level_buffer
  float speed_multiplier;  ///< Current speed multiplier
  int hi_score;            ///< Contains high score
  int ticks;               ///< Contains ticks (default 5000)
  float ticks_left;        ///< Current ticks
} game_stats_t;

/**
 * @enum color_pairs
 * @brief Enum for storage color pairs
 */
typedef enum {
  PAIR_EMPTY = 0,     ///< Color pair for empty cells
  PAIR_FIGURE_I = 2,  ///< Color pair for 'i' figure
  PAIR_FIGURE_O,      ///< Color pair for 'o' figure
  PAIR_FIGURE_S,      ///< Color pair for 's' figure
  PAIR_FIGURE_Z,      ///< Color pair for 'z' figure
  PAIR_FIGURE_T,      ///< Color pair for 't' figure
  PAIR_FIGURE_L,      ///< Color pair for 'l' figure
  PAIR_FIGURE_J,      ///< Color pair for 'j' figure
  PAIR_PROJECTION     ///< Color pair for profection of figure
} color_pairs;

/**
 * @enum UserAction_t
 * @brief Enum for user's action
 */
typedef enum {
  Start,      ///< Pressing ENTER
  Pause,      ///< Pressing 'P'
  Terminate,  ///< Pressing 'Q'
  Left,       ///< Pressing LEFT ARROW
  Right,      ///< Pressing RIGHT ARROW
  Up,         ///< Pressing UP ARROW
  Down,       ///< Pressing DOWN ARROW
  Action,     ///< Pressing SPACE
  Empty       ///< No actions
} UserAction_t;

/**
 * @enum Game_state
 * @brief Enum for current game state
 */
typedef enum {
  START = 0,  ///< Display intro scene
  SPAWN,      ///< Initialize figure and spawn
  MOVING,     ///< Moving current figure by user
  SHIFTING,   ///< Shifting figure by 1 "pixel" down
  COLLIDE,    ///< Attaching current figure to game field
  GAMEOVER,   ///< Printing game over
  PAUSE,      ///< Pause game
  EXIT_STATE  ///< Exit game
} Game_state;

/**
 * @struct map_t
 * @brief Structure for storage current figure and collision data
 */
typedef struct {
  int collision[ROWS_MAP][COLS_MAP];       ///< Array for collision data
  int current_figure[ROWS_MAP][COLS_MAP];  ///< Array for current figure data
} map_t;

/**
 * @struct GameInfo_t
 * @brief Structure for storage current game's info
 */
typedef struct {
  int **field;          ///< Array for field data
  int **next;           ///< Array for next figure data
  int score;            ///< Contains current score
  int high_score;       ///< Contains high score
  int level;            ///< Contains current level
  int speed;            ///< Contains current speed
  int pause;            ///< Contains state for using pause
  game_stats_t *stats;  ///< Pointer on structure game_stats_t
  map_t *map;           ///< Pointer on structure map_t
  figure_t *figure;     ///< Pointer on structure figure_t
} GameInfo_t;

#endif