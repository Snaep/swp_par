#include "strategies.h"

int RowStrategy( Sudoku* sud, int x, int y ) {
	return 0;
}
int ColStrategy( Sudoku* sud, int x, int y ) {
	return 0;
}
int BoxStrategy( Sudoku* sud, int x, int y ) {
	return 0;
}

static const Strategy strategies[] = {
	&RowStrategy,
	&ColStrategy,
	&BoxStrategy
};

Strategy* GetStrategies( unsigned int* ids, int ct ) {
	Strategy* retv;

	if( ct < 0 ) return NULL;

	retv = ( Strategy* ) malloc( sizeof( Strategy ) * ( ct + 1 ) );
	if( retv == NULL ) return NULL;

	//set strategies
	for( retv[ct--] = NULL; ct >= 0; ct--) {
		if( ids[ct] >= sizeof( strategies ) / sizeof( Strategy ) ) {
			free( retv );
			return NULL;
		}
		retv[ct] = strategies[ids[ct]];
	}

	return retv;
}