#include "stdafx.h"
#include <gtest/gtest.h>

#include "two_sum.h"
#include "reverse_int.h"

TEST(TestSum, Sum)
{
	std::vector<int> vec = { 3, 2, 4 };
	int target = 6;
	std::vector<int> a = other_twoSum(vec, target);
	ASSERT_TRUE(a.size() == 2);

}

TEST(TestReverse, reserseint) {
	int a = reverse(123);
	ASSERT_TRUE(a == 321);
	int b = reverse(-123);
	ASSERT_TRUE(b == -321);
	int c = reverse(120);
	ASSERT_TRUE(c == 21);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::cin.get();
	return 0;
}