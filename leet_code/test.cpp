#include "stdafx.h"
#include <gtest/gtest.h>

#include "two_sum.h"


TEST(TestSum, Sum)
{
	std::vector<int> vec = { 3, 2, 4 };
	int target = 6;
	std::vector<int> a = other_twoSum(vec, target);
	ASSERT_TRUE(a.size() == 2);

}


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}