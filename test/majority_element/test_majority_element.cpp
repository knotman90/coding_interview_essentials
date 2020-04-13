#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;

#include "majority_element_solution1.cpp"
#include "majority_element_solution2.cpp"




TEST(majority_element, test_empty_array)
{
	
	const std::vector<int> V = {};
	constexpr int expected = -1;
	EXPECT_EQ(expected, find_majority_element_linear(V));
}


TEST(majority_element, test_single_element)
{
	
	const std::vector<int> V = {1};
	constexpr int expected = 1;
	EXPECT_EQ(expected, find_majority_element_linear(V));
}

TEST(majority_element, test_all_different)
{
	
	const std::vector<int> V = {1,2,3,4,5,6,7,8};
	constexpr int expected = -1;
	EXPECT_EQ(expected, find_majority_element_linear(V));
}

TEST(majority_element, test_equal_times)
{
	
	const std::vector<int> V = {1,1,2,2};
	constexpr int expected = -1;
	EXPECT_EQ(expected, find_majority_element_linear(V));
}

TEST(majority_element, test_equal_times_plus_one)
{
	
	const std::vector<int> V = {2,1,1,2,2};
	constexpr int expected = 2;
	EXPECT_EQ(expected, find_majority_element_linear(V));
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

