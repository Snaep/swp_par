#pragma once

#include "sudoku.h"
#include "strategies.h"

typedef struct {

	Strategy* strategies;
	unsigned int solver;

	TCHAR filepath[512];

	Sudoku* sud;

} ParameterSet;

void ParameterSet_parse( int argc, TCHAR** argv, ParameterSet* dest );