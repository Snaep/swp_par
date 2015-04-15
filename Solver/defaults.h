#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <math.h>

#ifdef _DEBUG
#ifdef UNICODE
#define _EXIT(a) {_tprintf(_T("\nExiting in Module %s on Line %i\n"), __FILEW__, __LINE__); system("pause"); return a;}
#else
#define _EXIT(a) {_tprintf(_T("\nExiting in Module %s on Line %i\n"), __FILE__, __LINE__); system("pause"); return a;}
#endif
#else
#define _EXIT(a) {return a;}
#endif


#define ENV_NEWLINE _T('\n')
#define ENDOFSTRING _T('\0')