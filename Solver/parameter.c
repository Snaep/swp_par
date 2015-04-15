#include "parameter.h"
#include "solver.h"
#include <stdio.h>


void ParameterSet_parse( unsigned int argc, TCHAR** argv, ParameterSet* dest ) {
	unsigned int i, j;
	int ct; //counter for no of strategies
	unsigned int strats[10]; //buffer for strategies

	if( dest == NULL || argv == NULL ) return;
	

	memset( strats, 0, sizeof( int ) * 10 );
	dest->filepath[0] = 0;
	ct = 0;

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
			strats[ct++] = argv[i][3] - _T( '0' );
			break;
		default:
			_tprintf( _T( "Unknown parameter:%s\n" ), argv[i] );
			break;
		}
	}

	if( dest->filepath[0] == 0 ) return;

	dest->strategies = GetStrategies( strats, ct );
	if( dest->strategies == NULL ) return;

	//parse sudoku with delimiter ' '
	dest->sud = Sudoku_Parse( dest->filepath, ' ' );
}