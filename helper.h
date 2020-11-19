/* Header file "helper.h" */

/* Aurthor: Sami Khan
   Program last changed: 21/10/2019 */

#ifndef HELPER_H
#define HELPER_H

/* FUNCTION TO CHECK A BLOCK IN THE SUDOKU BOARD IS CORRECT */
bool check_box(int rowStart, int columnStart, char board[9][9], int digit);

/* FUNCTION TO FIND THE FIRST EMPTY CELL ON A SUDOKU BOARD */
pair <int, int> first_empty(char board[9][9]);

#endif
