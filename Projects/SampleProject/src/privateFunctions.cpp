//======== ======== ======== ======== ======== ======== ======== ========
///	\file
///
//======== ======== ======== ======== ======== ======== ======== ========

#include "privateFunctions.hpp"

#ifdef _WIN32
#	include <intrin.h>
#endif

bool parity(uint32_t p_data)
{
#ifdef _WIN32
	return (__popcnt(p_data) & 1) ? true : false;
#else
	return __builtin_parity(p_data) ? true : false;
#endif
}

bool bitTest(uint32_t p_value, uint8_t p_pos)
{
#ifdef _WIN32
	return _bittest(reinterpret_cast<const long*>(&p_value), p_pos) ? true : false;
#else
	return (p_value >> p_pos) & 0x01 ? true : false;
#endif
}

uint32_t bitExtract(uint32_t p_value, uint8_t p_pos, uint8_t p_size)
{
#ifdef _WIN32
	return _bextr_u32(p_value, p_pos, p_size);
#else
	return (p_value >> p_pos) & ((0x01 << p_size) - 1);
#endif
}
