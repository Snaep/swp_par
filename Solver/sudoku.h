#pragma once

#include "defaults.h"

#define CELL_POSSIBLE 1
#define CELL_IMPOSSIBLE 0
#define CELL_VALUE 0

#define CONTAINS_ROW 0
#define CONTAINS_COL 1
#define CONTAINS_BOX 2
#define NUM_ELEMENTS 3


typedef struct {

	//[y][x][0] = cellvalue
	//[y][x][1-N] = possibilities for cell
	int*** grid;

	//[contains_][col/row/box index][valueindex]
	//1: col/row/box contains value
	//0: col/row/box does not contain value
	int** contains[3];

	unsigned int length;
	unsigned int length_of_box;

} Sudoku;

Sudoku* Sudoku_Parse( TCHAR* filepath, TCHAR delimiter );

//returns 0: sudoku is solved and valid
//returns 1: sudoku in solved incorrectly or incompletly
int Sudoku_Validate( Sudoku* sud );

//Sets Cell to given value
//adds cell value to contains
//return S_FAIL if cell is not empty
//does not validate cell against other
int Sudoku_SetCell( Sudoku* sud, unsigned int x, unsigned int y, unsigned int value );
