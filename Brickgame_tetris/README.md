# Brickgame Tetris

My interpretation of classical puzzle video game. In this video game the goal is to achieve the highest score. The project consist of two parts for implement the Tetris game: the library that implements the game's logic and the terminal interface. The logic of the library is implemented using finite-state machine.

- Author: hollisgr

![pic](image/tetris1.png)

## Information
- Developed for Linux;
- Build program with makefile;
- To install the game use target "install";
- To play the game use target "play";
- To uninstall the game use target "uninstall";

## Controls

- To move block left: LEFT ARROW;
- To move block right: RIGHT ARROW;
- To move block to ground: DOWN ARROW;
- To rotate figure: SPACE;
- Pause/unpause: p;
- Quit: q;


## Implementation:
- The program is developed in C language of C11 standard using gcc compiler;
- The program is consist of two parts: the library implementing the logic of the tetris game, and the terminal interface using the ncurses.h library;
- The finite-state machine (FSM) is used to formalize the logic of the game;
- The program library code is located in the src/brick_game/tetris folder;
- The program interface code is located in the src/gui/cli folder;
- The program is built using the Makefile with targets: all, install, uninstall, clean, play, dist, test, report;
- The following mechanics is in the game:
    - Rotation of pieces;
    - Moving pieces horizontally;
    - Acceleration of the piece’s fall (when the button is pressed, the figure moves all the way down);
    - Display of the next piece;
    - Destruction of filled raws;
    - End of the game when the top border of the playing field is reached;
