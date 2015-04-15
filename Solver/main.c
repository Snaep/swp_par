#include "defaults.h"
#include "parameter.h"
#include "solver.h"


int _tmain( unsigned int argc, TCHAR** argv ) {
	ParameterSet params;
	Solver solver;
	int rc;
	
	memset( &params, 0, sizeof( ParameterSet ) );

	ParameterSet_parse( argc, argv, &params );

	if( params.strategies == NULL || params.strategies[0] == NULL ) {
		_tprintf( _T( "no strategies detected.\n" ) );
		_NOTIFYEXIT
		return 1;
	}

	if( params.sud == NULL ) {
		_tprintf( _T( "Unable to load/parse sudoku.\n" ) );
		_NOTIFYEXIT
		return 1;
	}
	//dickbutt
	solver = GetSolver( params.solver );
	if( solver == NULL ) {
		_tprintf( _T( "the specified parallelization mode is unsupported.\n" ) );
		_NOTIFYEXIT
		return 1;
	}

	//solve grid with obtained solver
	switch( rc = solver( params.sud, params.strategies ) ) {
	case SLV_SUCCESS:
		break;
	default:
		_tprintf( _T( "unknown error during solver execution ( %i )\n" ), rc );
		_NOTIFYEXIT
		return 1;
	}

	if( ValidateSudoku( params.sud ) != 0 ) {
		_tprintf( _T( "solution invalid.\n" ) );
		_NOTIFYEXIT
		return 1;
	}

	//let windows do the cleanup?
	//params.sud / params.strategies

	//Save solved Sudoku to file

	//exit
	return 0;
}
