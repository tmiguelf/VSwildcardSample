//======== ======== ======== ======== ======== ======== ======== ========
///	\file
///
//======== ======== ======== ======== ======== ======== ======== ========

#include <gtest/gtest.h>

#include <privateFunctions.hpp>


TEST(privateFunctions, reverseBits)
{
	struct TestCase
	{
		uint8_t sideA;
		uint8_t sideB;
	};

	const std::vector<TestCase> testData =
	{
		{0x00, 0x00},
		{0x01, 0x80},
		{0x02, 0x40},
		{0x04, 0x20},
		{0x08, 0x10},
		{0x55, 0xAA},
		{0x5F, 0xFA},
		{0x69, 0x96},
		{0xFF, 0xFF},
	};

	for(const TestCase testCase: testData)
	{
		ASSERT_EQ(reverseBits(testCase.sideA), testCase.sideB);
		ASSERT_EQ(reverseBits(testCase.sideB), testCase.sideA);
	}
}

TEST(privateFunctions, parity)
{
	struct TestCase
	{
		uint32_t	value;
		bool		parity;
	};

	const std::vector<TestCase> testData =
	{
		{0x00000000, false},
		{0x00000001, true},
		{0x00000002, true},
		{0x00000003, false},
		{0x00000010, true},
		{0x00000111, true},
		{0x00000020, true},
		{0x11111111, false},
		{0x11111113, true},
		{0x80000000, true},
		{0x80000001, false},
		{0x80000002, false},
		{0x80000003, true},
		{0x80000010, false},
		{0x80000111, false},
		{0x80000020, false},
		{0x91111111, true},
		{0x91111113, false},
		{0xFFFFFFFF, false},
	};

	for(const TestCase testCase: testData)
	{
		ASSERT_EQ(parity(testCase.value), testCase.parity);
	}

}

TEST(privateFunctions, bitTest)
{
	for(uint32_t val = 1, pos = 0; val; val = val << 1, ++pos)
	{
		for(uint8_t i = 0; i < 32; ++i)
		{
			if(i == pos)
			{
				ASSERT_TRUE(bitTest(val, i));
			}
			else
			{
				ASSERT_FALSE(bitTest(val, i));
			}
		}
	}
}

TEST(privateFunctions, bitExtract)
{
	struct TestCase
	{
		uint32_t	value;
		uint8_t		pos;
		uint8_t		size;
		uint32_t	result;
	};

	const std::vector<TestCase> testData =
	{
		{0xFFFFFFFF, 0,  0, 0x00000000},
		{0xFFFFFFFF, 0,  1, 0x00000001},
		{0xFFFFFFFF, 0, 31, 0x7FFFFFFF},
		{0xFFFFFFFD, 1, 30, 0x3FFFFFFE},
		{0x12345678, 0, 32, 0x12345678},
		{0x12345678, 4, 28, 0x01234567},
		{0x12345678, 4, 24, 0x00234567},
	};

	for(const TestCase testCase: testData)
	{
		EXPECT_EQ(bitExtract(testCase.value, testCase.pos, testCase.size), testCase.result);
	}
}
