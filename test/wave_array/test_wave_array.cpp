#include <gtest/gtest.h>
#include <bits/stdc++.h>

#include "testing_utilities.h"

#include "wave_array_solution1.cpp"
#include "wave_array_solution2.cpp"

bool is_wave_sorted(const std::vector<int>& A)
{
	if(A.size() <= 2)
		return true;
	bool sign = A[0] >= A[1];
	for(int i = 0 ; i < A.size()-1; i++)
	{
		if(sign && !(A[i] >= A[i+1]))
			return false;
		if(!sign && !(A[i] <= A[i+1]))
			return false;
		sign = !sign;
	}
	return true;
}

TEST(wave_array, test_sorted_inverse)
{
	std::vector<int> A = {10,9,8,7,6,5,4,3,2,1,0};
	const std::vector<int> expected = {};

	{
		std::vector<int> result_sorting = wave_sorting(A);
		EXPECT_TRUE(is_wave_sorted(result_sorting));
	}

	{
		std::vector<int> result_sorting = wave_linear(A);
		std::cout<<result_sorting<<std::endl;
		EXPECT_TRUE(is_wave_sorted(result_sorting));
	}
}

TEST(wave_array, test_custom2)
{
	std::vector<int> A = {20, 10, 8, 6, 4, 2};
	const std::vector<int> expected = {};

	{
		std::vector<int> result_sorting = wave_sorting(A);
		EXPECT_TRUE(is_wave_sorted(result_sorting));
	}
}

TEST(wave_array, test_custom3)
{
	std::vector<int> A = {20, 10, 8, 6, 4, 2};
	const std::vector<int> expected = {};

	{
		std::vector<int> result_sorting = wave_sorting(A);
		EXPECT_TRUE(is_wave_sorted(result_sorting));
	}
}

TEST(wave_array, test_custom4)
{
	std::vector<int> A = {2, 4, 6, 8, 10, 20};
	const std::vector<int> expected = {};

	{
		std::vector<int> result_sorting = wave_sorting(A);
		EXPECT_TRUE(is_wave_sorted(result_sorting));
	}
}

TEST(wave_array, test_custom_all_same)
{
	std::vector<int> A = {10, 10,10,10,10,10,10,10,10};
	const std::vector<int> expected = {};

	{
		std::vector<int> result_sorting = wave_sorting(A);
		EXPECT_TRUE(is_wave_sorted(result_sorting));
	}
}

TEST(wave_array, test_custom1)
{
	std::vector<int> A = {10, 5, 6, 3, 2, 20, 100, 80};
	const std::vector<int> expected = {};

	{
		std::vector<int> result_sorting = wave_sorting(A);
		EXPECT_TRUE(is_wave_sorted(result_sorting));
	}
}

TEST(wave_array, test_empty)
{
	std::vector<int> A = {};
	const std::vector<int> expected = {};

	{
		std::vector<int> result_sorting = wave_sorting(A);
		EXPECT_TRUE(is_wave_sorted(result_sorting));
	}
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

