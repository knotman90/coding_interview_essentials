#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;

#include "sorted_array_intersection_solution1.cpp"
#include "sorted_array_intersection_solution2.cpp"


TEST(sorted_array_intersection, test_empty_intersection)
{
	
	std::vector<int> A1= {1,2,3,4};
	std::vector<int> A2= {5,6,7,8};

	const std::vector<int> expected;
	
	EXPECT_EQ(expected, sorted_arrays_intersection_bruteforce(A1,A2));
	
}


TEST(sorted_array_intersection, test_empty)
{
	
	std::vector<int> A1= {};
	std::vector<int> A2= {};

	std::vector<int> expected;
	
	EXPECT_EQ(expected, sorted_arrays_intersection_bruteforce(A1,A2));
	
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

