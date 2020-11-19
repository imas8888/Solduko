/* Header file "sudoku.h" */

/* Aurthor: Sami Khan
   Program last changed: 10/10/2019 */

#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
using namespace std;

/* FUNCTION TO LOAD A BOARD FROM FILE*/
void load_board(const char* filename, char board[9][9]);

/* FUNCTION TO DISPLAY A BOARD */
void display_board(const char board[9][9]);

/* FUNCTION TO CHECK IF A BOARD IS COMPLETE */
bool is_complete(const char bard[9][9]);

/* FUNCTION THAT CHECKS IF A MOVE IS VALID */
bool make_move(string position, int digit, char board[9][9]);

/* FUNCTION THAT SAVES THE BOARD TO A FILE */
bool save_board(string filename, char board[9][9]);

/* FUNCTION THAT ATTEMPTS TO SOLVE A BOARD */
bool solve_board(char board[9][9]);

#endif
