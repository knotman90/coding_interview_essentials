#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "palindrome_partitioning2_solution1.cpp"
#include "palindrome_partitioning2_solution2.cpp"



TEST(palindrome_partitioning2, test1)
{
	
	const string s = "itopinonavevnonipoti";
	constexpr int expected = 0;
	ASSERT_EQ(expected, palindrome_partitioning2_bruteforce(s));
	ASSERT_EQ(expected, palindrome_partitioning2_DP_topdown(s));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

