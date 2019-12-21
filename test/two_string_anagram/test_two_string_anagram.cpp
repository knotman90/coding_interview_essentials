#include <gtest/gtest.h>
#include <bits/stdc++.h>

#include "two_string_anagram_brute_force.cpp"
#include "two_string_anagram_sorting.cpp"
#include "two_string_anagram_histogram.cpp"

using std::string;



TEST(two_string_anagram_sorting, given_two_empty_string_result_should_be_zero)
{
	string a = "";
	string b (a);
	constexpr int expected_value = 0;
	EXPECT_EQ(0, solution_sorting(a,b));
	EXPECT_EQ(0, solution_brute_force(a,b));
	EXPECT_EQ(0, solution_histogram(a,b));
}

TEST(two_string_anagram_sorting, given_two_equal_string_result_should_be_zero)
{
	string a = "aaaa";
	string b (a);
	constexpr int expected_value = 0;
	EXPECT_EQ(0, solution_sorting(a,b));
	EXPECT_EQ(0, solution_brute_force(a,b));
	EXPECT_EQ(0, solution_histogram(a,b));
}

TEST(two_string_anagram_sorting, given_two_string_one_reverse_than_the_other_result_should_be_zero)
{
	string a = "tear";
	string b (a.rbegin(), a.rend());
	constexpr int expected_value = 0;

	EXPECT_EQ(expected_value, solution_sorting(a,b));
	EXPECT_EQ(expected_value, solution_brute_force(a,b));
	EXPECT_EQ(expected_value, solution_histogram(a,b));
}

TEST(two_string_anagram_sorting, given_two_strings_differet_length_result_should_be_minus1)
{
	string a = "aaaa";
	string b ("bbbbbbbbb");
	constexpr int expected_value = -1;

	EXPECT_EQ(expected_value, solution_sorting(a,b));
	EXPECT_EQ(expected_value, solution_brute_force(a,b));
	EXPECT_EQ(expected_value, solution_histogram(a,b));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}