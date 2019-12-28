#include <gtest/gtest.h>
#include <bits/stdc++.h>

#include "stairs_climbing_solution1.cpp"
#include "stairs_climbing_solution2.cpp"

using std::string;



TEST(stairs_climbing, test1_2_fibonacci)
{
	std::vector<int> expected = {1, 1, 2};/*, 2, 3, 5, 8, 13, 21, 34, 55, 89, 
								144, 233, 377, 610, 987, 1597, 2584, 4181, 
								6765, 10946, 17711, 28657, 46368, 75025, 
								121393, 196418, 317811};*/

	const std::vector<int> step_sizes = {1,2};
	for(int i = 2 ; i < expected.size() ; i++)
	{
		EXPECT_EQ(expected[i],stair_climbing_fibonacci(i));
		EXPECT_EQ(expected[i],stair_climbing_arbitrary(i, step_sizes));
	}
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

