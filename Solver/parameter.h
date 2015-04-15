#pragma once

#include "sudoku.h"

typedef struct {

	int strategies[8];
	int parallelization;

	TCHAR filepath[512];

	Sudoku* sud;

} ParameterSet;

void ParameterSet_parse( int argc, TCHAR** argv, ParameterSet* dest );