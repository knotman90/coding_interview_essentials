#include <gtest/gtest.h>
#include <bits/stdc++.h>

#include "first_positive_missing_solution1.cpp"
#include "first_positive_missing_solution2.cpp"
#include "first_positive_missing_solution3.cpp"
#include "first_positive_missing_solution4.cpp"


TEST(first_positive_missing, test_0)
{
	const int expected = 1;
	std::vector<int> A = {0};
	
	EXPECT_EQ(expected,first_positive_missing_sorting(std::vector<int>(A)));
	EXPECT_EQ(expected,first_positive_missing_linear_space(std::vector<int>(A)));
	EXPECT_EQ(expected,first_positive_missing_bruteforce1(std::vector<int>(A)));
	EXPECT_EQ(expected,first_positive_missing_bruteforce2(std::vector<int>(A)));
	EXPECT_EQ(expected,first_positive_missing_constant_space(std::vector<int>(A)));
}


TEST(first_positive_missing, test_duplicate_0)
{
	std::vector<int> A = {0,0,0,0,0,0,0,0,0};
	const int expected = 1;
	EXPECT_EQ(expected,first_positive_missing_sorting(A));
	EXPECT_EQ(expected,first_positive_missing_linear_space(A));
}

TEST(first_positive_missing, test_duplicate_1)
{
	std::vector<int> A = {1,1,1,1,1,1,1,1,1,1,1};
	const int expected = 0;
	EXPECT_EQ(expected,first_positive_missing_sorting(A));
		EXPECT_EQ(expected,first_positive_missing_linear_space(A));
}

TEST(first_positive_missing, test_consecutive_0_to_10)
{
	std::vector<int> A = {0,1,2,3,4,5,6,7,8,9,10};
	const int expected = 11;
	EXPECT_EQ(expected,first_positive_missing_sorting(A));
		EXPECT_EQ(expected,first_positive_missing_linear_space(A));
}

TEST(first_positive_missing, test_consecutive_minus10_to_10)
{
	std::vector<int> A = {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10};
	const int expected = 11;
	EXPECT_EQ(expected,first_positive_missing_sorting(A));
		EXPECT_EQ(expected,first_positive_missing_linear_space(A));
}

TEST(first_positive_missing, test_consecutive_minus10_to_10_6_and_7_missing)
{
	std::vector<int> A = {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,8,9,10};
	const int expected = 6;
	EXPECT_EQ(expected,first_positive_missing_sorting(A));
		EXPECT_EQ(expected,first_positive_missing_linear_space(A));
}

TEST(first_positive_missing, test_all_negative)
{
	std::vector<int> A = {-1,-9,-5,-7,-8,-9,-9,-8,-7,-1,-5,-8,-9,-546546};
	const int expected = 0;
	EXPECT_EQ(expected,first_positive_missing_sorting(A));
		EXPECT_EQ(expected,first_positive_missing_linear_space(A));
}

TEST(first_positive_missing, test_one_negative)
{
	std::vector<int> A = {-54};
	const int expected = 0;
	EXPECT_EQ(expected,first_positive_missing_sorting(A));
		EXPECT_EQ(expected,first_positive_missing_linear_space(A));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

