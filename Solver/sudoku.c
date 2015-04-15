#include "sudoku.h"
#include "helper.h"
#include <stdlib.h>

Sudoku* Sudoku_Parse( char* filepath, char delimiter ) {
	Sudoku* sud;
	FILE* fptr;
	TCHAR buffer[256];
	TCHAR** line;
	int read, i, row, pi;

	fptr = _tfopen( filepath, _T( "r" ) );
	if( fptr == NULL ) return NULL;
		
	sud->length = 0;
	read = 0;
	
	while( fread( &buffer[read], sizeof( TCHAR ), 1, fptr ) != 0 ) {
		if( read > 1 && buffer[read] == _T('\n') && buffer[read - 1] == _T('\r') ) {
			line = string_split( buffer, delimiter );
			if( line == NULL || line[0] < 1) goto CLEANUP;

			if( sud == NULL ) {
				sud = ( Sudoku* ) malloc( sizeof( Sudoku ) );
				if( sud == NULL ) goto CLEANUP;

				sud->length = line[0];
				sud->grid = ( int** ) calloc( ( int ) line[0], sizeof( int* ) );
				if( sud->grid == NULL ) goto CLEANUP;
				for( i = 0; i < line[0]; i++ ) sud->grid[i] = ( int* ) malloc( sizeof( int ) * ( int ) line[0] );
				row = 0;
			}

			for( i = 0; i < line[0]; i++ ) {
				if( !int_parse( line[i], &pi ) ) goto CLEANUP;
				sud->grid[row][i] = pi;
			}

			row++;
		}
	}

	goto END;
CLEANUP:
	if( sud != NULL ) {
//TODO: free grid;
		free( sud );
		sud = NULL;
	}
END:
	if( line != NULL ) {
		for( i = line[0]; i; i-- ) free( line[i] );
		free( line );
	}
	fclose( fptr );
	return sud;
}
