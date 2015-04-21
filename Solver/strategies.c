#include "strategies.h"

int Strategy_SinglePossibility( Sudoku* sud, int x, int y ) {
	unsigned int i;
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

int Strategy_MissingCol( Sudoku* sud, int x ) {
	unsigned int i;
	int possibility;

	possibility = 0;
	for( i = 1; i <= sud->length; i++ ) {
		if( sud->contains[CONTAINS_COL][x][i] == FALSE ) {
			if( possibility != 0 ) return 0;
			possibility = i;
		}
	}

	for( i = 0; i < sud->length; i++ ) {
		if( sud->grid[i][x][CELL_VALUE] == 0 ) {
			Sudoku_SetCell( sud, x, i, possibility );
			return 1;
		}
	}

	_tprintf( _T( "reached unreachable statement\r\nModule: %s\r\nLine:%i\r\nDescription:\
				  \r\nCol is missing 1 value but no cell is empty\r\n" ), __FILE__, __LINE__ );
	
	return 0;
}
int Strategy_MissingRow( Sudoku* sud, int y ) {
	unsigned int i;
	int possibility;

	possibility = 0;
	for( i = 1; i <= sud->length; i++ ) {
		if( sud->contains[CONTAINS_ROW][y][i] == FALSE ) {
			if( possibility != 0 ) return 0;
			possibility = i;
		}
	}

	for( i = 0; i < sud->length; i++ ) {
		if( sud->grid[y][i][CELL_VALUE] == 0 ) {
			Sudoku_SetCell( sud, i, y, possibility );
			return 1;
		}
	}

	_tprintf( _T( "reached unreachable statement\r\nModule: %s\r\nLine:%i\r\nDescription:\
				  \r\nRow is missing 1 value but no cell is empty\r\n" ), __FILE__, __LINE__ );

	return 0;
}
int Strategy_MissingBox( Sudoku* sud, int x, int y ) {
	unsigned int i, j, bi;
	int possibility;

	bi = ( y / sud->length_of_box ) * sud->length_of_box + x / sud->length_of_box;

	possibility = 0;
	for( i = 1; i <= sud->length; i++ ) {
		if( sud->contains[CONTAINS_BOX][bi][i] == FALSE ) {
			if( possibility != 0 ) return 0;
			possibility = i;
		}
	}

	for( j = y; j < y + sud->length_of_box; j++ ) {
		for( i = x; i < x + sud->length_of_box; i++ ) {
			if( sud->grid[j][i][CELL_VALUE] == 0 ) {
				Sudoku_SetCell( sud, i, j, possibility );
				return 1;
			}
		}
	}

	_tprintf( _T( "reached unreachable statement\r\nModule: %s\r\nLine:%i\r\nDescription:\
				  				  \r\nBox is missing 1 value but no cell is empty\r\n" ), __FILE__, __LINE__ );

	return 0;
}