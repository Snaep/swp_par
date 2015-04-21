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

//checks if cell has only 1 possibility left and sets the value in grid
//returns amount of changed cells  (0,1)
int Strategy_OnePossibility( Sudoku* sud, int x, int y );