#pragma once

#include <tchar.h>

typedef struct {

	int** grid;

	int length;

} Sudoku;

Sudoku* Sudoku_Parse( TCHAR* filepath, TCHAR delimiter );