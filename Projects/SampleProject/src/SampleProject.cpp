//======== ======== ======== ======== ======== ======== ======== ========
///	\file
///
//======== ======== ======== ======== ======== ======== ======== ========

#include "SampleProject/SampleProject.hpp"
#include "privateFunctions.hpp"


uint32_t SomeOverlyComplicatedFunction(uint32_t p_1, uint8_t p_2, uint8_t p_3)
{
	if(parity(p_1))
	{
		return bitExtract(p_1, p_2, p_3);
	}

	if(bitTest(p_1, p_3))
	{
		return bitExtract(p_1, p_3, p_2);
	}

	return bitExtract(p_1, p_2, reverseBits(p_3));
}
