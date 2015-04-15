#include "sudoku.h"
#include "helper.h"

Sudoku* Sudoku_Parse( char* filepath, char delimiter ) {
	Sudoku* sud;
	FILE* fptr;
	TCHAR buffer[256];
	TCHAR** line;
	int read, i, row, pi;

	if( _tfopen_s( &fptr, filepath, _T( "r" ) ) != 0 ) return NULL;

	read = 0;
	sud = NULL;
	
	while( fread( &buffer[read], sizeof( TCHAR ), 1, fptr ) != 0 ) {
		if( read >= 1 && buffer[read] == _T('\n') ) {
			buffer[read + 1] = 0;
			line = string_split( buffer, delimiter );
			if( line == NULL || (int)line[0] < 1) goto CLEANUP;
			line[0]--;

			if( sud == NULL ) {
				sud = ( Sudoku* ) malloc( sizeof( Sudoku ) );
				if( sud == NULL ) goto CLEANUP;

				sud->length = (int)line[0];
				sud->grid = ( int** ) calloc( ( int ) line[0], sizeof( int* ) );
				if( sud->grid == NULL ) goto CLEANUP;
				for( i = 0; i < (int)line[0]; i++ ) sud->grid[i] = ( int* ) malloc( sizeof( int ) * ( int ) line[0] );
				row = 0;
			}

			for( i = 1; i <= (int)line[0]; i++ ) {
				if( int_parse( line[i], &pi ) != 0 ) goto CLEANUP;
				sud->grid[row][i - 1] = pi;
			}

			row++;
		}
		read++;
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
		for( i = ( int ) line[0]; i; i-- ) {
			if( line[i] != NULL ) free( line[i] );
		}
		free( line );
	}
	fclose( fptr );
	return sud;
}
