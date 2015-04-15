#include "sudoku.h"

TCHAR* ReadAllBytes( TCHAR * file ) {
	FILE *fptr;
	long len;
	TCHAR* retv;

	if( _tfopen_s( &fptr, file, "r" ) != 0 ) return NULL;

	fseek( fptr, 0, SEEK_END );
	len = ftell( fptr );

	retv = ( TCHAR* ) malloc( len * sizeof( TCHAR ) + sizeof( TCHAR ) );
	if( retv != NULL ) {
		fseek( fptr, 0, SEEK_SET );
		fread( retv, 1, len, fptr );
		retv[len] = '\0';
	}

	fclose( fptr );

	return retv;
}

Sudoku* Sudoku_Parse( char* filepath, char delimiter ) {
	Sudoku* sud;
	TCHAR* file;
	int i, rowindex, cellvalue, cellindex;

	//read file
	file = ReadAllBytes( filepath );
	if( file == NULL ) return NULL;

	//create sudoku
	sud = ( Sudoku* ) malloc( sizeof( Sudoku ) );
	if( sud == NULL ) goto CLEANUP;

	sud->length = 0;

	//determine grid size by counting occurences of delimiter in first row
	for( i = 0; file[i] != ENV_NEWLINE; i++ ) {
		if( file[i] == delimiter ) sud->length++;
	}

	//minimum size of grid is 2x2 (1 2 \n3 4 \n)
	if( sud->length < 2 ) goto CLEANUP;

	//allocate grid
	sud->grid = ( int** ) calloc( ( int ) sud->length, sizeof( int* ) );
	if( sud->grid == NULL ) goto CLEANUP;

	//allocate grid rows
	for( i = 0; i < sud->length; i++ ) {
		sud->grid[i] = ( int* ) malloc( sizeof( int ) * sud->length );
		if( sud->grid[i] == NULL ) goto CLEANUP;
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
			sud->grid[rowindex][cellindex++] = cellvalue;
			if( cellindex == sud->length ) {
				cellindex = 0;
				//if no of rows == no of cols + 1 end parsing
				if( ++rowindex == sud->length ) break;
			}
			cellvalue = 0;
		//if current tchar is end of line increment rowindex
		} else if( file[i] == ENV_NEWLINE ) {
			rowindex++;
		//if current tchar is not ctrl tchar, parse as cell content
		} else {
			cellvalue *= 10;
			cellvalue += file[i] - '0';
		}
	}

	//skip cleanup
	goto END;
CLEANUP:
	//free sudoku if allocated
	if( sud != NULL ) {

		//free sudoku grid if allocated
		if( sud->grid != NULL ) {
			for( i = 0; i < sud->length; i++ ) if( sud->grid[i] != NULL ) free( sud->grid[i] );

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
