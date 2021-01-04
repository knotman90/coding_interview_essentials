#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "next_greater_element_solution1.cpp"
#include "next_greater_element_solution2.cpp"




TEST(next_greater_element, test1)
{
	const std::vector<int> A = {4,1,2};
    const std::vector<int> B = {1,3,4,2};
    const std::vector<int> expected = {-1,2,-1};
	{
    auto ans = next_greater_element_I_bruteforce(A,B);
    EXPECT_EQ(expected, ans);
    }

    {
    auto ans = next_greater_element_I_set(A,B);
    EXPECT_EQ(expected, ans);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

