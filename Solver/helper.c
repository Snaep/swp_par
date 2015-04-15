#include "helper.h"

#include <stdlib.h>


TCHAR ** string_split( TCHAR* string, TCHAR splitchar ) {
	short substrings[512];
	int length;
	int counts;
	int i, newsize;
	TCHAR** retv;

	length = 0;
	counts = 0;

	if( string == NULL ) return NULL;

	while( 1 ) {
		if( string[length] == '\0' ) break;
		else if( string[length] == splitchar ) substrings[counts++] = length;
		length++;
	}
	substrings[counts] = length;
	counts++;

	retv = ( TCHAR** ) malloc( sizeof( TCHAR* ) * ( counts ) );
	if( retv == NULL ) return NULL;

	retv[0] = (TCHAR*)counts;
	if( counts == 1 ) substrings[0] = length;

	retv[1] = ( TCHAR* ) malloc( sizeof( TCHAR ) * ( substrings[0] + 1 ) );
	if( retv[1] == NULL ) {
		free( retv );
		return NULL;
	}
	memcpy( retv[1], string, substrings[0] * sizeof( TCHAR ) );
	retv[1][substrings[0]] = '\0';

	for( i = 2; i <= counts; i++ ) {
		newsize = sizeof( TCHAR ) * ( substrings[i - 1] - substrings[i - 2] - 1);
		retv[i] = ( TCHAR* ) malloc( newsize );
		if( retv[i] == NULL ) {
			while( i-- ) free( retv[i] );
			free( retv );
			return NULL;
		}
		memcpy( retv[i], &string[substrings[i - 2] + 1], newsize );
		retv[i][newsize] = '\0';
	}
	

	return retv;
}

int int_parse( TCHAR* input, int* result ) {
	int i;

	if( input == 0 || result == 0 ) return 1;
	for( i = 0; input[i]; i++ ) if( !_istdigit( input[i] ) ) return 1;
	
	*result = _ttoi( input );

	return 0;
}
