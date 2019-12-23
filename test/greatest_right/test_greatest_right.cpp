#include <gtest/gtest.h>
#include <bits/stdc++.h>

#include "greatest_right_bruteforce.cpp"
#include "greatest_right_final.cpp"
#include "greatest_right_final2.cpp"

using std::string;



TEST(greatest_right, given_empty_array_should_return_empty_array)
{
	const std::vector<int> A = {};
	std::vector<int> expected = {};

	{
		//bruteforce
		std::vector<int> input = A;
		greatest_right_bruteforce(input);
		EXPECT_EQ(expected, input);	
	}

	{
		//final1
		std::vector<int> input = A;
		greatest_right_final1(input);
		EXPECT_EQ(expected, input);	
	}

	{
		//final2
		std::vector<int> input = A;
		greatest_right_final2(input);
		EXPECT_EQ(expected, input);	
	}
}

TEST(greatest_right, given_one_element_array_should_return_empty_array)
{
	std::vector<int> A = {123};
	std::vector<int> expected = {-1};
	
	{
		//bruteforce
		std::vector<int> input = A;
		greatest_right_bruteforce(input);
		EXPECT_EQ(expected, input);	
	}

	{
		//final1
		std::vector<int> input = A;
		greatest_right_final1(input);
		EXPECT_EQ(expected, input);	
	}

	{
		//final2
		std::vector<int> input = A;
		greatest_right_final2(input);
		EXPECT_EQ(expected, input);	
	}

}

TEST(greatest_right, given_example1_array_should_return_empty_array)
{
	std::vector<int> A = {15, 22, 12, 13, 12, 19, 0, 2};
	std::vector<int> expected = {22, 19, 19, 19, 19, 2, 2, -1};

		{
		//bruteforce
		std::vector<int> input = A;
		greatest_right_bruteforce(input);
		EXPECT_EQ(expected, input);	
	}

	{
		//final1
		std::vector<int> input = A;
		greatest_right_final1(input);
		EXPECT_EQ(expected, input);	
	}

	{
		//final2
		std::vector<int> input = A;
		greatest_right_final2(input);
		EXPECT_EQ(expected, input);	
	}
}

TEST(greatest_right, given_example2_array_should_return_empty_array)
{
	std::vector<int> A = {2, 3, 1, 9};
	std::vector<int> expected = {9, 9, 9, -1};

		{
		//bruteforce
		std::vector<int> input = A;
		greatest_right_bruteforce(input);
		EXPECT_EQ(expected, input);	
	}

	{
		//final1
		std::vector<int> input = A;
		greatest_right_final1(input);
		EXPECT_EQ(expected, input);	
	}

	{
		//final2
		std::vector<int> input = A;
		greatest_right_final2(input);
		EXPECT_EQ(expected, input);	
	}
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}