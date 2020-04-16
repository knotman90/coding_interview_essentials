#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;

#include "first_unique_char_solution1.cpp"
#include "first_unique_char_solution2.cpp"




TEST(first_unique_char, test1)
{
	
	EXPECT_EQ(0,1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

