#pragma once
#include "parameter.h"

//no error occured
#define SLV_SUCCESS 0

typedef int( *Solver )( Sudoku* grid, unsigned int strategies );

//returns address of solver representing given parallelization mode
//returns NULL on error
Solver GetSolver( unsigned int parallelization );
int logic_solve ( Sudoku* sud );