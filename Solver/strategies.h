#pragma once

#include "sudoku.h"

//check if a row is missing only 1 value
#define STRAT_MISSING_ROW (1<<0)
//check if a col is missing only 1 value
#define STRAT_MISSING_COL (1<<1)
//check if a box is missing only 1 value
#define STRAT_MISSING_BOX (1<<2)

//check if a cell has only 1 possibility left
#define STRAT_SINGLE_POSSIBILITY (1<<3)

//define number of rules to solve Sudoku
#define RULE_CNT 6

int ( *rules[RULE_CNT] )( Sudoku* );

//checks if cell has only 1 possibility left and sets the value in grid
//returns amount of changed cells  (0,1)
int Strategy_SinglePossibility ( Sudoku* sud, int x, int y );//Equals Naked Single
int Strategy_MissingCol ( Sudoku* sud, int x );
int Strategy_MissingRow ( Sudoku* sud, int y );
int Strategy_MissingBox ( Sudoku* sud, int x, int y );

int logic_solve ( Sudoku* sud );
//checks for single possible number in row
int rule1 ( Sudoku* sud );
//checks for single possilbe number in col
int rule2 ( Sudoku* sud );
//checks for single possible number in each box
int rule3 ( Sudoku* sud );
int rule4 ( Sudoku* sud );
int rule5 ( Sudoku* sud );
int rule6 ( Sudoku* sud );