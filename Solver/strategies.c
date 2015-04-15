#include "strategies.h"

static const Strategy strategies[] = {

};

Strategy* GetStrategies( unsigned int* ids, unsigned int ct ) {
	Strategy* retv = ( Strategy* ) malloc( sizeof( Strategy ) * ( ct + 1 ) );
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