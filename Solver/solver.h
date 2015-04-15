#pragma once
#include "parameter.h"

//no error occured
#define SLV_SUCCESS 0

//possibly param error
#define SLV_INVALID_PARALLELIZATION -1

//warning:1 or more strategies are incompatible
//with selected parallelization
#define SLV_INCOMPATIBLE_STRATEGY 1

typedef int( *Solver )( Sudoku* grid, int( **strategies )( Sudoku* grid, int x, int y ) );

//returns address of solver representing given parallelization mode
//returns NULL on error
Solver GetSolver( unsigned int parallelization );