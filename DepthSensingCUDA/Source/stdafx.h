
//TODO MATTHIAS put eigen in here

#include <stdio.h>

#ifdef _WIN32
	#include <WinSock2.h>
	#include <windows.h>
	#include <DXUT.h>
#else

#include <cstdint>
#define HRESULT uint32_t
#define S_OK 0x0
#define S_FALSE 0x1
#endif

#include "mLib.h"
