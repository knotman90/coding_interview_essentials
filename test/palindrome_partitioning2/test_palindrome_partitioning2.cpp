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
	
	for(const auto [s, expected] : {
		std::pair<std::string, int>("itopinonavevanonipoti", 0),
		std::pair<std::string, int>("ab", 1),
		std::pair<std::string, int>("abc", 2),
		std::pair<std::string, int>("abac",1),
		std::pair<std::string, int>("abacfbf",2),
		std::pair<std::string, int>("ababbbabbababa",3),
		std::pair<std::string, int>("acac",1),
		std::pair<std::string, int>("adda",0),
	})
	{
		ASSERT_EQ(expected, palindrome_partitioning2_bruteforce(s)) <<"failed for "<<s<<std::endl;
		ASSERT_EQ(expected, palindrome_partitioning2_DP_topdown (s)) <<"failed for "<<s<<std::endl;
	}
	
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

