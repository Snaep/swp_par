#pragma once

#include "sudoku.h"

typedef int( *Strategy )( Sudoku* grid, int x, int y );

//return NULL terminated array of strategyptr
Strategy* GetStrategies( unsigned int* ids, unsigned int ct );