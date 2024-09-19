/**
 * @file intro.c
 * @brief Prints intro graphics in terminal
 * @details
 * @author hollisgr / S21
 * @date 10.07.2024
 *
 */

#include "tetris.h"

#define HEIGHT 5
#define WIDTH 40

void print_intro_massage() {
  int welcome[HEIGHT][WIDTH] = {
      {
          1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
          1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {
          1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0,
          0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {
          1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0,
          0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {
          1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0,
          0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {
          0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1,
          1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
      }};

  int to[HEIGHT][WIDTH] = {
      {
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1,
          1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {
          0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0,
          0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
          1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
  };

  int tetris[HEIGHT][WIDTH] = {
      {
          1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0,
          1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {
          0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {
          0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0,
          1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {
          0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0,
          0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {
          0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1,
          1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
  };
  int color_1 = rand() % 7;
  int color_2 = rand() % 7;
  int color_3 = rand() % 7;
  int color_4 = rand() % 7;

  for (int i = 1; i < 20; i++)
    for (int j = 1; j < 40; j++) {
      // PRINT_PROJECTION(i, j, PAIR_FIGURE_J);
      PRINT_PROJECTION(i, j, (color_1));
    }

  for (int i = 0; i < HEIGHT; i++)
    for (int j = 0; j < WIDTH; j++) {
      int frame1 = welcome[i][j];
      int frame2 = to[i][j];
      int frame3 = tetris[i][j];
      if (frame1 == 1) {
        // PRINT_CELL(i + 1, j + 4, PAIR_FIGURE_S);
        PRINT_CELL(i + 2, j + 4, color_2);
      }
      if (frame2 == 1) {
        // PRINT_CELL(i + 7, j + 1, PAIR_FIGURE_Z);
        PRINT_CELL(i + 8, j + 1, color_3);
      }
      if (frame3 == 1) {
        // PRINT_CELL(i + 13, j + 8, PAIR_FIGURE_T);
        PRINT_CELL(i + 14, j + 8, color_4);
      }
    }
  mvprintw(22, 12, "PRESS ENTER TO START");
  print_tips();
}

void print_tips() {
  mvprintw(5, 44, "  TETRIS by hollisgr");
  mvprintw(10, 44, "       CONTROLS:");
  mvprintw(11, 44, "-----------------------");
  mvprintw(12, 44, "Move left:  ARROW_LEFT");
  mvprintw(13, 44, "Move right: ARROW_RIGHT");
  mvprintw(14, 44, "Move down:  ARROW_DOWN");
  mvprintw(15, 44, "Rotate:     SPACE");
  mvprintw(16, 44, "Start:      ENTER");
  mvprintw(17, 44, "Pause:      P");
  mvprintw(18, 44, "Quit:       Q");
  mvprintw(19, 44, "Tips:       F1");
  mvprintw(20, 44, "----------------------");
}