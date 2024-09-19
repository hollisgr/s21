/**
 * @file defines.h
 * @brief Defines and macroses for library
 * @details
 * @author hollisgr / S21
 * @date 10.07.2024
 *
 */

#ifndef DEFINES_H
#define DEFINES_H

#include "tetris.h"

#define BOARD_N 20  // height of the game field
#define BOARD_M 20  // width of the game field
#define HUD_WIDTH 12
#define MAP_PADDING 3
#define ROWS_MAP BOARD_N + 2
#define COLS_MAP BOARD_M + 2
#define BOARDS_BEGIN 2
#define INTRO_MESSAGE "Press ENTER to start"
#define ENTER_KEY 10
#define FIGURE_SIZE 5

#define GET_USER_INPUT getch()
#define WIN_INIT(time)    \
  {                       \
    initscr();            \
    noecho();             \
    curs_set(0);          \
    keypad(stdscr, TRUE); \
    timeout(time);        \
  }

#define MVPRINTW(y, x, ...) \
  mvprintw(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), __VA_ARGS__)
#define MVADDCH(y, x, c) mvaddch(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), c)

#define PRINT_CELL(y, x, pair) \
  attron(COLOR_PAIR(pair));    \
  MVADDCH(y, x, ' ');          \
  attroff(COLOR_PAIR(pair));

#define PRINT_PROJECTION(y, x, pair) \
  attron(COLOR_PAIR(pair));          \
  MVADDCH(y, x, ACS_CKBOARD);        \
  attroff(COLOR_PAIR(pair));

#endif