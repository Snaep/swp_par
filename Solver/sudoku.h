#pragma once

#include "defaults.h"

typedef struct {

	int** grid;

	int length;
	int length_of_box;

} Sudoku;

Sudoku* Sudoku_Parse( TCHAR* filepath, TCHAR delimiter );