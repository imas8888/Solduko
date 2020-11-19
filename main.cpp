/* Main file "main.cpp" */

/* Aurthor: Sami Khan
   Program last changed: 22/10/2019 */

#include <iostream>
#include "sudoku.h"
#include <time.h>

using namespace std;

/* MAIN FUNCTION */
int main() {

  char board[9][9];
  char boardC[9][9];
  
  cout << "============= Testing load_board() functions =============" << "\n\n";

  cout << "Calling load_board():" << '\n';
  load_board("easy.dat", board);

  cout << '\n' << "Displaying Sudoku board with display_board():" << '\n';
  display_board(board);
  cout << "Done!" << "\n\n";

  cout << "=================== Testing the completeness ===================" << "\n\n";

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << "\n\n";

  load_board("easy-solution.dat", boardC);
  cout << "Board is ";
  if (!is_complete(boardC))
    cout << "NOT ";
  cout << "complete." << "\n\n";

  cout << "=================== Testing move ===================" << "\n\n";

  load_board("easy.dat", board);
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8",'1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  cout << "=================== Testing saving file ===================" << "\n\n";

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << '\n';
  else
    cout << "Save board failed." << '\n';
  cout << '\n';
  
  cout << "=================== Trying to solve the boards ===================" << "\n\n";

  load_board("easy.dat", board);
  if (solve_board(board))
  {
    cout << "The 'easy' board has a solution:" << '\n';
    display_board(board);
  }
  else 
    cout << "A solution cannot be found." << '\n';
  cout << '\n';

  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution cannot be found." << '\n';
  cout << '\n';

  load_board("test.dat", board);
  if (solve_board(board))
  {
    cout << "The 'test' board has a solution:" << '\n';
    display_board(board);
  }
  else
    cout << "A solution cannot be found." << '\n';
  cout << '\n';

  cout << "=================== Checking run-time of code ===================" << "\n\n";

  clock_t beginTime = clock(); // clock used here to calculate runtime for each compilation
  float duration = 0.0;
  
  load_board("mystery1.dat", board);
  if (solve_board(board))
  {
    cout << "The 'mystery1' board has a solution:" << '\n';
    display_board(board);
    duration = ((float)(clock() - beginTime))/CLOCKS_PER_SEC;
    cout << "This took " << duration << " seconds to complete.\n";
  }
  else
  {
    cout << "A solution cannot be found." << '\n';
    duration = 0.0;
  }
  cout << '\n';

  beginTime = clock();
  load_board("mystery2.dat", board);
  if (solve_board(board))
  {
    cout << "The 'mystery2' board has a solution:" << '\n';
    display_board(board);
    duration = ((float)(clock() - beginTime))/CLOCKS_PER_SEC;
    cout << "This took " << duration << " seconds to complete.\n";
  }
  else
  {
    cout << "A solution cannot be found." << '\n';
    duration = 0.0;
  }
  cout << '\n';

  beginTime = clock();
  load_board("mystery3.dat", board);
  if (solve_board(board))
  {
    cout << "The 'mystery3' board has a solution:" << '\n';
    display_board(board);
    duration = ((float)(clock() - beginTime))/CLOCKS_PER_SEC;
    cout << "This took " << duration << " seconds to complete.\n";
  }
  else
  {
    cout << "A solution cannot be found." << '\n';
    duration = 0.0;
  }
  cout << '\n'; 

  return 0;
}
/* END OF MAIN FUNCTION */
