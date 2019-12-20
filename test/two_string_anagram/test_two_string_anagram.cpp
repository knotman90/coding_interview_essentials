#include <gtest/gtest.h>
#include <bits/stdc++.h>

#include "two_string_anagram_sorting.cpp"

using std::string;


TEST(two_string_anagram_sorting, given_two_equal_string_result_should_be_zero)
{
	string a = "aaaa";
	string b (a);
	EXPECT_EQ(0, solution_sorting(a,b));
}

TEST(two_string_anagram_sorting, given_two_string_one_reverse_than_the_other_result_should_be_zero)
{
	string a = "tear";
	string b (a.rbegin(), a.rend());	
	EXPECT_EQ(0, solution_sorting(a,b));
}

TEST(two_string_anagram_sorting, given_two_strings_differet_length_result_should_be_minus1)
{
	string a = "aaaa";
	string b ("bbbbbbbbb");
	EXPECT_EQ(-1, solution_sorting(a,b));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}