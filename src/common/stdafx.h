// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef WIN32
#include <SDKDDKVer.h>

#define NOMINMAX    
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Header Files:
#include <windows.h>
#include <windowsx.h>
#include <wrl.h>
#include <KnownFolders.h>
#include <shlobj.h>

// C RunTime Header Files
#include <malloc.h>
#include <tchar.h>
#include <cassert>
#include <cstdlib>

#else

// C RunTime Header Files
#include <malloc.h>
#include <cassert>
#include <cstdlib>
#include <cmath>

#include <aio.h>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdarg>

#include <sys/stat.h>
#include <sys/types.h>
#include "my_adapter.h"
#endif

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <mutex>
#include <limits>
#include <algorithm>
#include <mutex>

// math API
#include <DirectXMath.h>
using namespace DirectX;



// TODO: reference additional headers your program requires here
