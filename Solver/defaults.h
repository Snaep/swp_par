#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <math.h>

#ifdef _DEBUG
#ifdef UNICODE
#define _NOTIFYEXIT {_tprintf(_T("\nExiting in Module %s on Line %i\n"), __FILEW__, __LINE__); system("pause");}
#else
#define _NOTIFYEXIT {_tprintf(_T("\nExiting in Module %s on Line %i\n"), __FILE__, __LINE__); system("pause");}
#endif
#else
#define _NOTIFYEXIT
#endif


#define ENV_NEWLINE _T('\n')
#define ENDOFSTRING _T('\0')