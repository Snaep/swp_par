#include "solver.h"

int SolveSequential( Sudoku* sud, unsigned int strategies ) {
	int x, y, i;
	int changes;
	
	do {
		changes = 0;

		if( strategies & STRAT_SINGLE_POSSIBILITY ) {
			for( x = 0; x < sud->length; x++ ) {
				for( y = 0; y < sud->length; y++ ) {
					changes += Strategy_SinglePossibility( sud, x, y );
				}
			}
		}

	} while( changes != 0 );

	return changes;
}





static Solver solver[] = {
	&SolveSequential
};

Solver GetSolver( unsigned int parallelization ) {
	if( parallelization >= sizeof( solver ) / sizeof( Solver ) ) return NULL;
	return solver[parallelization];
}
