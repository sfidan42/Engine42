#pragma once

#ifdef E42_PLATFORM_WINDOWS
	#ifdef E42_BUILD_DLL
		#define E42_API __declspec(dllexport)
	#else
		#define E42_API __declspec(dllimport)
	#endif
#else
	#error Engine42 only support Windows!
#endif
