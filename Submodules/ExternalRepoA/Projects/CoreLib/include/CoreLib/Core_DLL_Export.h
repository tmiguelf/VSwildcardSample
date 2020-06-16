//======== ======== ======== ======== ======== ======== ======== ========
///	\file
///		Provides utilities to link dynamic libraries/binaries (.dll .so)
//======== ======== ======== ======== ======== ======== ======== ========

#pragma once

#ifdef _WIN32
#	define CORE_DLL_IMPORT		__declspec(dllimport)
#	define CORE_DLL_EXPORT		__declspec(dllexport)
#	define CORE_DLL_LOCAL
#else
#	if __GNUC__ >= 4
#		define CORE_DLL_IMPORT	__attribute__ ((visibility ("default")))
#		define CORE_DLL_EXPORT	__attribute__ ((visibility ("default")))
#		define CORE_DLL_LOCAL	__attribute__ ((visibility ("hidden")))
#	else
#		define CORE_DLL_IMPORT
#		define CORE_DLL_EXPORT
#		define CORE_DLL_LOCAL
#	endif
#endif
