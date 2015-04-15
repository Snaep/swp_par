#include "helper.h"
#include <stdio.h>

int main( int argc, char** argv ) {
	char test[] = "Hallo Peter 123 ";
	char** ret;
	int i;

	ret = string_split( test, 'Z' );

	for( i = 1; i <= ret[0]; i++ ) {
		printf( "%s\n", ret[i] );
	}

	getchar();

	return 0;
}