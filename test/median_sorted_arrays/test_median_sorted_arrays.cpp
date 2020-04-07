#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;

#include "median_sorted_arrays_solution1.cpp"
#include "median_sorted_arrays_solution2.cpp"


TEST(median_sorted_arrays, test_when_A_is_empty)
{
	std::vector<int> A{};
	std::vector<int> B{1,2,3};
	constexpr double expected = 2;
	EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_naive(A,B));
}

TEST(median_sorted_arrays, test_when_B_is_empty)
{
	std::vector<int> A{1,2,3};
	std::vector<int> B{};
	constexpr double expected = 2;
	EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_naive(A,B));
}

TEST(median_sorted_arrays, test_when_A_all_smaller_than_B)
{
	std::vector<int> A{1,2,3};
	std::vector<int> B{5,6,7,8};
	constexpr double expected = 5;
	EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_naive(A,B));
}

TEST(median_sorted_arrays, test_when_A_all_smaller_than_B_even)
{
	std::vector<int> A{1,2,3};
	std::vector<int> B{4,5,6};
	constexpr double expected = 4.5;
	EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_naive(A,B));
}



TEST(median_sorted_arrays, test_odd1)
{
	std::vector<int> A{1,3,5};
	std::vector<int> B{2,4};
	constexpr double expected = 3;
	EXPECT_EQ(expected, mediam_sorted_arrays_naive(A,B));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

