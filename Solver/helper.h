#pragma once

#include <tchar.h>

TCHAR ** string_split( TCHAR* string, TCHAR splitchar );
int int_parse( TCHAR* input, int* result );