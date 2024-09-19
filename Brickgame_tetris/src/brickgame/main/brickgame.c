#include "tetris.h"
#include <locale.h>

/**
 * @file brickgame.c
 * @brief Main file for game initialization 
 * @details 
 * @author hollisgr / S21
 * @date 10.07.2024
 * 
 */

int main() {
    Game_state state = START;
    WIN_INIT(50);
    setlocale(LC_ALL, "");
    game_loop(state);
    endwin();
    return 0;
}
