#pragma once

#define UNICODE
#define _UNICODE

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

#ifdef _DEBUG
#ifdef UNICODE
#define _ONEXIT() _tprintf(_T("\nExiting in Module %s, Function %s on Line %i\n"), __FILEW__, __FUNCTIONW__, __LINE__); system("pause")
#else
#define _ONEXIT() _tprintf(_T("\nExiting in Module %s, Function %s on Line %i\n"), __FILE__, __FUNCTION__, __LINE__); system("pause")
#endif
#else
#define _ONEXIT()
#endif
