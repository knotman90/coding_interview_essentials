#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;

#include "valid_parenthesis_solution1.cpp"
#include "valid_parenthesis_solution2.cpp"




TEST(valid_parenthesis, test1)
{
	
	EXPECT_EQ(0,1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

