# Solduko

Soduko solver. Take the input as a `.dat` file with `.` used to indicate blanks which need to be filled in. This solver uses an efficient backtracking algorithm to fill in the board.

### Installation
1. Download and unzip this repository
2. Use GNU Make to create an executable using the following command in this directory `make -f makefile`
3. Run the executable named: *sudoku* (or *sudoku.exe* depending on OS)

### How to Use
* The program initially prints a few boards just to show that the code works
* The easy and medium test boards will then be solved
* To input your own board:
  * Make changes to `test.dat`
  * Re-run the program and see the result
