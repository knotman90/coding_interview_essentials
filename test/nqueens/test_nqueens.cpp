#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "nqueens_solution1.cpp"
#include "nqueens_solution2.cpp"




TEST(nqueens, testFrom1To6)
{
	
    
	EXPECT_EQ(1,nqueen_bruteforce(1).size());
    
    EXPECT_EQ(0,nqueen_bruteforce(2).size());

    EXPECT_EQ(0,nqueen_bruteforce(3).size());

    EXPECT_EQ(2,nqueen_bruteforce(4).size());

    EXPECT_EQ(10,nqueen_bruteforce(5).size());

    EXPECT_EQ(4,nqueen_bruteforce(6).size());

    EXPECT_EQ(40,nqueen_bruteforce(7).size());

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

