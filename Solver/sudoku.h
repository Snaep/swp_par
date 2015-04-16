#pragma once

#include "defaults.h"

typedef struct {

	int** grid;

	int length;
	int length_of_box;

	int* buffer;

} Sudoku;

Sudoku* Sudoku_Parse( TCHAR* filepath, TCHAR delimiter );

//returns 0: sudoku is solved and valid
//returns 1: sudoku in solved incorrectly or incompletly
int ValidateSudoku( Sudoku* sud );
