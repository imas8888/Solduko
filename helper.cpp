/* Implementation file: "helper.cpp" */

/* Aurthor: Sami Khan
   Program last changed: 21/10/2019 */

#include <fstream>
using namespace std;

/* FUNCTION TO CHECK A BLOCK IN THE SUDOKU BOARD IS CORRECT */
bool check_box(int rowStart, int columnStart, char board[9][9], int digit)
{
  for (int i = 0; i <= 2; i++)
    {
      for (int j = 0; j <= 2; j++)
	{
	  if (board[rowStart+i][columnStart+j] ==(char)(digit + 48)) //converting digit to char for comparison
	    {
	      return false;
	    }
	}
    }
    return true;
}
/* END OF FUNCTION */

/* FUNCTIN TO FIND THE FIRST EMPTY CELL ON A SUDOKU BOARD */
pair <int, int> first_empty(char board[9][9])
{
  for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j <9; j++)
	{
	  if (board[i][j] == '.') //"." is the blank character in the .dat file
	    {
	      return make_pair(i, j);
	    }
	}
    }
  return make_pair(10,10); //this is the case where the board is full
}

/* END OF FUNCTION */
