//======== ======== ======== ======== ======== ======== ======== ========
///	\file
///
//======== ======== ======== ======== ======== ======== ======== ========

#pragma once

#include <cstdint>

/// \brief reverses the bit order in a byte
[[nodiscard]] inline constexpr uint8_t reverseBits(uint8_t p_bits)
{
	// http://graphics.stanford.edu/~seander/bithacks.html#ReverseByteWith64BitsDiv
	// unsigned char b; // reverse this (8-bit) byte
	//
	// b = (b * 0x0202020202ULL & 0x010884422010ULL) % 1023;
	//
	// The multiply operation creates five separate copies of the 8-bit byte pattern to fan-out into a 64-bit value.
	// The AND operation selects the bits that are in the correct (reversed) positions, relative to each 10-bit groups of bits.
	// The multiply and the AND operations copy the bits from the original byte so they each appear in only one of the 10-bit sets.
	// The reversed positions of the bits from the original byte coincide with their relative positions within any 10-bit set.
	// The last step, which involves modulus division by 2^10 - 1, has the effect of merging together each set of 10 bits
	// (from positions 0-9, 10-19, 20-29, ...) in the 64-bit value.
	// They do not overlap, so the addition steps underlying the modulus division behave like or operations.

	return static_cast<uint8_t>(((p_bits * 0x0202020202u) & 0x010884422010u) % 1023);
}

//TODO: Can't constexpr because there's no constexpr intrinsics support :(
/// \brief intrinsics optimized parity check
[[nodiscard]] bool parity(uint32_t p_data);

/// \brief intrinsics optimized bit check
[[nodiscard]] bool bitTest(uint32_t p_value, uint8_t p_pos);

/// \brief intrinsics optimized bit extract
[[nodiscard]] uint32_t bitExtract(uint32_t p_value, uint8_t p_pos, uint8_t p_size);
