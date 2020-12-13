#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "items_in_containers_amazon_solution1.cpp"
#include "items_in_containers_amazon_solution2.cpp"




TEST(items_in_containers_amazon, test1)
{
	const std::string s = "|*|*|";
    const std::vector<std::pair<int,int>> Q ={{0,2},{0,4}};
    const std::vector<int> expected = {1,2};

	{
        EXPECT_EQ(expected,items_in_containers_naive(s,Q));
    }
    {
        EXPECT_EQ(expected,items_in_containers_lineartime(s,Q));
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

