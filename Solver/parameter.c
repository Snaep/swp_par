#include "parameter.h"
#include "solver.h"
#include <stdio.h>


void ParameterSet_parse( TCHAR** argv, ParameterSet* dest ) {
	unsigned int i, j;
	if( dest == NULL ) return;
	
	dest->strategies = 0;
	dest->filepath[0] = 0;
	i = ( unsigned int ) - 1;

	while(argv[++i] != NULL) {
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
			dest->solver = argv[i][5] - _T( '0' );
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
			j = argv[i][3] - _T( '0' );
			if( argv[i][4] >= '0' && argv[i][4] <= '9' ) { //2. Stelle
				j *= 10;
				j += argv[i][4] - _T( '0' );
			}

			dest->strategies |= j;
			break;
		default:
			_tprintf( _T( "Unknown parameter:%s\n" ), argv[i] );
			break;
		}
	}

	if( dest->filepath[0] == 0 ) return;
	
	//parse sudoku with delimiter ' '
	dest->sud = Sudoku_Parse( dest->filepath, ' ' );
}