/* Implementation file "sudoku.cpp" */

/* Aurthor: Sami Khan
   Program last changed: 21/10/2019 */

#include <iostream>
#include <fstream>
#include <cassert>
#include <map>
#include "sudoku.h"
#include "helper.h"

using namespace std;

/* FUNCTION TO LOAD A BOARD FROM A FILE */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << '\n';
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
  assert(row == 9);
}
/* END OF FUNCTION */

/* FUNCTION TO PRINT THE FRAME OF THE SUDOKU BOARD */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << '\n';
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << '\n';
}
/* END OF FUNCTION */

/* FUNCTION TO PRINT A ROW OF THE SUDOKU BOARD */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << '\n';
}
/* END OF FUNCTION */

/* FUNCTION TO DISPLAY A BOARD */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << '\n';
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}
/* END OF FUNCTION */

/* FUNCTION TO CHECK IF A BOARD IS COMPLETE */
bool is_complete(const char board[9][9])
{
  for (int i = 0; i < 9; i++)
    {
      for (int j =0; j < 9; j++)
	{
	  if ((!isdigit(board[i][j])) || board[i][j] == '0') //checks the entry is a digit and its above 0 (i.e. 1-9)
	    {
	      return false;
	    }
	}
    }
  return true;
}
/* END OF FUNCTION */

/* FUNCTION THAT CHECKS IF A MOVE IS VALID */
bool make_move(string position, int digit, char board[9][9])
{
  map<char, int> rowToInt= {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}};
  // this map is used to convert the row letter into a number so it can be used in an array
  
  int rowNum = rowToInt[position.at(0)];
  int columnNum =(int)position.at(1) - 49; // -49 here to convert to ascii properly and move from 1->0 (counting)
  
  if (board[rowNum][columnNum] != '.') // "." is the blank character used in the sudoku board
    {
      return false;
    }
  
  for (int i = 0; i < 9; i++)
    {
      if (board[rowNum][i] ==(char)(digit + 48)) //check if digit already appears in the row
	{
	  return false;
	}
      if (board[i][columnNum] == (char)(digit + 48)) // check if digit already appears in the column
	{
	  return false;
	}
    }
  
  switch(rowNum) // checking if the digit exists anywhere in the 3x3 block the cell is contained in
    {
    case 0:case 1:case 2:
      switch(columnNum)
	{
	case 0:case 1:case 2:
	  return check_box(0,0,board,digit); //helper function
	case 3:case 4:case 5:
	  return check_box(0,3,board,digit);
	case 6:case 7:case 8:
	  return check_box(0,6,board,digit);
	}
    case 3:case 4:case 5:
      switch(columnNum)
	{
	case 0:case 1:case 2:
	  return check_box(3,0,board,digit);
	case 3:case 4:case 5:
	  return check_box(3,3,board,digit);
	case 6:case 7:case 8:
	  return check_box(3,6,board,digit);
	}
    case 6:case 7:case 8:
      switch(columnNum)
	{
	case 0:case 1:case 2:
	  return check_box(6,0,board,digit);
	case 3:case 4:case 5:
	  return check_box(6,3,board,digit);
	case 6:case 7:case 8:
	  return check_box(6,6,board,digit);
	}
    }
  return true;
} 
/* END OF FUNCTION */

/* FUNCTION THAT SAVES THE BOARD TO A FILE */
bool save_board(string filename, char board[9][9])
{
  ofstream myFile (filename);
  if (myFile.is_open()) // checks if file is open
    {
      for (int i = 0; i <= 8; i++)
	{
	  for (int j = 0; j <= 8; j++)
	    {
	      myFile << board[i][j]; // writing board digit by digit to the file
	    }
	  myFile << "\n"; // adding new line at the end of each row
	}
      myFile.close();
      return true;
    }
    return false;
}
/* END OF FUNCTION */

/* FUNCTION THAT ATTEMPTS TO SOLVE A BOARD */
bool solve_board(char board[9][9])
{
  map<int, char> intToRow= {{0, 'A'}, {1, 'B'}, {2, 'C'}, {3, 'D'}, {4, 'E'}, {5, 'F'}, {6, 'G'}, {7, 'H'}, {8, 'I'}};
  // this map is used to convert row number back to a letter so it can be used in "make_move" function

  if (first_empty(board) == make_pair(10,10)) //if the board is complete
    {
      return true;
    }

  int rowNum = first_empty(board).first;
  int columnNum = first_empty(board).second;

  for (int digit = 1; digit <= 9; digit++)
    {
      if (make_move(intToRow[rowNum] + to_string(columnNum+1), digit, board)) // checks if move is possible
	{
	  board[rowNum][columnNum] = (char)(digit +48); // changes the entry in board to digit
	  if (solve_board(board)) //recursive step
	    {
	      return true;
	    }
	  board[rowNum][columnNum] = '.'; // if value does not work, the function will revert any changes to board
	}
    }
  return false;
}
/* END OF FUNCTION */
