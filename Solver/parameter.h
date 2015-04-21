#pragma once

#include "sudoku.h"
#include "strategies.h"

typedef struct {

	unsigned int strategies;
	unsigned int solver;

	TCHAR filepath[512];

	Sudoku* sud;

} ParameterSet;

void ParameterSet_Parse( TCHAR** argv, ParameterSet* dest );