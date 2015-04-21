#include "strategies.h"

int Strategy_SinglePossibility( Sudoku* sud, int x, int y ) {
	int i;
	int possibility;

	possibility = 0;
	for( i = 1; i <= sud->length; i++ ) {
		if( sud->grid[y][x][i] == CELL_POSSIBLE ) {
			if( possibility != 0 ) return 0;
			possibility = i;
		}
	}
	
	Sudoku_SetCell( sud, x, y, possibility );
	return 1;
}
