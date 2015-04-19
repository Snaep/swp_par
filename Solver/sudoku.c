#include "sudoku.h"

TCHAR* ReadAllBytes( TCHAR * file ) {
	FILE *fptr;
	long len;
	TCHAR* retv;

	if( _tfopen_s( &fptr, file, _T( "r" ) ) != 0 ) return NULL;

	fseek( fptr, 0, SEEK_END );
	len = ftell( fptr );

	retv = ( TCHAR* ) malloc( len * sizeof( TCHAR ) + sizeof( TCHAR ) );
	if( retv != NULL ) {
		fseek( fptr, 0, SEEK_SET );
		fread( retv, 1, len, fptr );
		retv[len] = _T( '\0' );
	}

	fclose( fptr );

	return retv;
}

Sudoku* Sudoku_Parse( char* filepath, char delimiter ) {
	Sudoku* sud;
	TCHAR* file;
	int i, j, rowindex, cellvalue, cellindex;

	//read file
	file = ReadAllBytes( filepath );
	if( file == NULL ) return NULL;

	//create sudoku
	sud = ( Sudoku* ) calloc( 1, sizeof( Sudoku ) );
	if( sud == NULL ) goto CLEANUP;
	
	//determine grid size by counting occurences of delimiter in first row
	for( i = 0; file[i] != ENV_NEWLINE; i++ ) {
		if( file[i] == delimiter ) sud->length++;
	}

	//minimum size of grid is 2x2 (1 2 \n3 4 \n)
	if( sud->length < 2 ) goto CLEANUP;

	//allocate grid
	sud->grid = ( int*** ) calloc( sud->length, sizeof( int** ) );
	if( sud->grid == NULL ) goto CLEANUP;

	//allocate grid rows
	for( i = 0; i < sud->length; i++ ) {
		sud->grid[i] = ( int** ) calloc( sud->length, sizeof( int* ) );
		if( sud->grid[i] == NULL ) goto CLEANUP;

		for( j = 0; j < sud->length; j++ ) {
			sud->grid[i][j] = ( int* ) malloc( ( 1 + sud->length ) * sizeof( int* ) ); //content + n possibilities
			if( sud->grid[i][j] == NULL ) goto CLEANUP;
			memset( sud->grid[i][j], CELL_POSSIBLE, sizeof( int ) * ( sud->length + 1 ) );
		}
	}

	//allocate contains helper
	for( i = 0; i < 3; i++ ) {
		sud->contains[i] = ( int** ) calloc( sud->length, sizeof( int* ) );
		if( sud->contains[i] == NULL ) goto CLEANUP;
		
		for( j = 0; j < sud->length; j++ ) {
			sud->contains[i][j] = ( int* ) calloc( sud->length + 1, sizeof( int ) );
			if( sud->contains[i][j] == NULL ) goto CLEANUP;
		}
	}

	//calculate box length
	sud->length_of_box = ( int ) ( 0.5f + sqrt( sud->length ) );	
	cellvalue = 0;
	cellindex = 0;
	rowindex = 0;

	//parse grid
	for( i = 0; file[i] != ENDOFSTRING; i++ ) {
		//if current tchar is delimiter, finish cell
		if( file[i] == delimiter ) {
			SetCell( sud, cellindex++, rowindex, cellvalue );
			if( cellindex == sud->length ) {
				cellindex = 0;
				//if no. of rows == no. of cols + 1 end parsing
				if( ++rowindex == sud->length ) break;
			}				
			cellvalue = 0;			
		//if current tchar is end of line increment rowindex
		} else if( file[i] == ENV_NEWLINE ) {
			rowindex++;
		//if current tchar is not ctrl tchar, parse as cell content
		} else {
			cellvalue *= 10;
			cellvalue += file[i] - _T( '0' );
		}
	}

	//skip cleanup
	goto END;
CLEANUP:
	//free sudoku if allocated
	if( sud != NULL ) {

		//free sudoku grid if allocated
		if( sud->grid != NULL ) {
			for( i = 0; i < sud->length; i++ ) {
				if( sud->grid[i] != NULL ) {
					for( j = 0; j < sud->length; j++ ) {
						if( sud->grid[i][j] != NULL ) free( sud->grid[i][j] );
					}
					free( sud->grid[i] );
				}
			}

			free( sud->grid );
		}

		free( sud );
		sud = NULL;
	}
END:
	//free loaded file
	if( file != NULL ) free( file );
	return sud;
}

int ValidateSudoku( Sudoku* sud ) {
	int i, j, m, n;
	int* buffer;

	buffer = malloc( sizeof( int ) * sud->length + sizeof( int ) );
	if( buffer == NULL ) return 1;

	//test all rows / cols / boxes
	for( i = 0; i < sud->length; i++ ) {

		//test row
		memset( buffer, 0, sizeof( int ) * sud->length );
		for( j = 0; j < sud->length; j++ ) {
			if( sud->grid[i][j] == 0 ) goto ERROR; //if cell is empty return error
			if( buffer[sud->grid[i][j] != 0] ) goto ERROR; //if previous cell contains value return error
			buffer[sud->grid[i][j][0]] = 1; //store cell value
		}

		//test col
		memset( buffer, 0, sizeof( int ) * sud->length );
		for( j = 0; j < sud->length; j++ ) {
			if( sud->grid[j][i] == 0 ) goto ERROR; //if cell is empty return error
			if( buffer[sud->grid[j][i] != 0] ) goto ERROR; //if previous cell contains value return error
			buffer[sud->grid[j][i][0]] = 1; //store cell value
		}
	}


	//test box
	memset( buffer, 0, sizeof( int ) * sud->length );
	for( i = 0; i < sud->length; i += sud->length_of_box ) {
		for( j = 0; j < sud->length; j += sud->length_of_box ) {

			for( m = 0; m < sud->length_of_box; m++ ) {
				for( n = 0; n < sud->length_of_box; n++ ) {
					if( buffer[sud->grid[i + m][j + n][0]] != 0 ) goto ERROR;
					buffer[sud->grid[i + m][j + n][0]] = 1;
				}
			}
		}
	}

	free( buffer );
	return 0;
ERROR:
	free( buffer );
	return 1;
}

int SetCell( Sudoku* sud, int x, int y, int value ) {
	int bi;
	int retv = sud->grid[x][y][0];
	
	bi = (y / sud->length_of_box) * sud->length_of_box + x / sud->length_of_box;

	//store value in grid
	sud->grid[x][y][0] = value;

	//store value in contains
	sud->contains[CONTAINS_COL][x][value] = 1;
	sud->contains[CONTAINS_ROW][y][value] = 1;
	sud->contains[CONTAINS_BOX][bi][value] = 1;

	//remove other cells possibility for value


	return retv;
}
