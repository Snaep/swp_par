#include "defaults.h"
#include "parameter.h"
#include "parallel.h"

//0:ok
//1:nok
//prüft, ob mindestens eine Strategie ausgewählt wurde
int test_strat( ParameterSet* params ) {
	int i;
	for( i = 0; i < sizeof( params->strategies ) / sizeof( int ); i++ ) if( params->strategies[i] != 0 ) return 0;
	return 1;
}

int _tmain(int argc, TCHAR** argv) {
	ParameterSet params;

	ParameterSet_parse( argc, argv, &params );

	if( params.sud == NULL ) {
		_tprintf( _T( "Das Sudoku konnte nicht geladen werden.\n" ) );
		_ONEXIT();
		return 1;
	}

	if( test_strat( &params ) != 0 ) {
		_tprintf( _T( "Keine Strategien ausgewählt.\n" ) );
		_ONEXIT();
		return 1;
	}

	switch( params.parallelization ) {
	case PAR_SEQ:
		_tprintf( _T( "yey" ) );
		break;
	default:
		_tprintf( _T( "Der Parallelisierungsmodus ( %i ) wird nicht unterstützt\n" ), params.parallelization );
		_ONEXIT();
		return 1;
	}

	_ONEXIT();
	return 0;
}