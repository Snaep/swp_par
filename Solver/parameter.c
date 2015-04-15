#include "parameter.h"
#include <stdio.h>


void ParameterSet_parse( int argc, TCHAR** argv, ParameterSet* dest ) {
	int i, j;

	if( dest == NULL || argv == NULL ) return;

	for( i = 0; i < sizeof( dest->strategies ) / sizeof( int ); i++ ) dest->strategies[i] = 0;

	dest->filepath[0] = 0;

	for( i = 1; i < argc; i++ ) {
		if( argv[i][0] != _T( '-' ) ) continue;

		//Parameter:
		//strategies:
		// -st[0-9]
		//parallelization:
		// -par=[0-9]
		//sudoku filepath:
		// -sud={GUID}.tmp

		switch( argv[i][2] ) {	
		case _T( 'a' ): //par
			dest->parallelization = argv[i][5] - _T( '0' );
			break;
		case _T( 'u' ): //sud
			j = 5;
			while( argv[i][j] ) {
				dest->filepath[j - 5] = argv[i][j];
				j++;
			}
			dest->filepath[j - 5] = 0;
			break;
		case _T( 't' ): //st
			dest->strategies[argv[i][3] - _T( '0' )] = 1;
			break;
		default:
			_tprintf( _T( "Unknown parameter:%s\n" ), argv[i] );
			break;
		}
	}

	if( dest->filepath[0] == 0 ) return;

	dest->sud = Sudoku_Parse( dest->filepath, ' ' );
}