#include "solver.h"

int SolveSequential( Sudoku* sud, int( **strategies )( Sudoku* grid, int x, int y ) ) {
	int x, y, i;
	int changes;
	
	do {
		changes = 0;

		//Local operations
		for( y = 0; y < sud->length; y++ ) {
			for( x = 0; x < sud->length; x++ ) {
				//if cell is empty(0)
				//try strategies until
				//cell value is set(!= 0)
				//all strategies were used(strategies[i] == NULL)
				if( sud->grid[y][x] == 0 ) {
					for( i = 0; strategies[i] != NULL; i++ ) {
						//call strategy and set cell value
						sud->grid[y][x] = ( *strategies[i] )( sud, x, y );
						//if strategy changed cell value, 
						//update no of changes and move to next cell
						if( sud->grid[y][x] != 0 ) {
							changes++;
							break;
						}
					}
				}
			}
		}

		//Global operationen

		//Area opearations

	} while( changes != 0 );

	//return 0
	return changes;
}

static Solver solver[] = {
	&SolveSequential
};

Solver GetSolver( unsigned int parallelization ) {
	if( parallelization >= sizeof( solver ) / sizeof( Solver ) ) return NULL;
	return solver[parallelization];
}
