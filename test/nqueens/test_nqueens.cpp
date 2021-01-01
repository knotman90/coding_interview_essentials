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



TEST(nqueens, testFrom1To6OnePerRow)
{
	
    
    EXPECT_EQ(1,nqueen_one_per_row(1).size());
    
    EXPECT_EQ(0,nqueen_one_per_row(2).size());

    EXPECT_EQ(0,nqueen_one_per_row(3).size());

    EXPECT_EQ(2,nqueen_one_per_row(4).size());

    EXPECT_EQ(10,nqueen_one_per_row(5).size());

    EXPECT_EQ(4,nqueen_one_per_row(6).size());

    EXPECT_EQ(40,nqueen_one_per_row(7).size());

}


TEST(nqueens, testFrom1To6_bruteforce)
{
	
    
	EXPECT_EQ(1,nqueen_bruteforce(1).size());
    EXPECT_EQ(1,nqueen_one_per_row(1).size());
    
    EXPECT_EQ(0,nqueen_bruteforce(2).size());

    EXPECT_EQ(0,nqueen_bruteforce(3).size());

    EXPECT_EQ(2,nqueen_bruteforce(4).size());

    EXPECT_EQ(10,nqueen_bruteforce(5).size());

    EXPECT_EQ(4,nqueen_bruteforce(6).size());


}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

