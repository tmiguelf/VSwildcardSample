//======== ======== ======== ======== ======== ======== ======== ========
///	\file
///
//======== ======== ======== ======== ======== ======== ======== ========

#pragma once

#include <CoreLib/Core_DLL_Export.h>

#ifdef _SampleProject_EXPORTS_
#	define SampleProject_API CORE_DLL_EXPORT
#else
#	define SampleProject_API CORE_DLL_IMPORT
#endif // _SampleProject_EXPORTS_

