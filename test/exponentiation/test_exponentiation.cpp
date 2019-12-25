#include <gtest/gtest.h>
#include <bits/stdc++.h>

#include "exponentiation_solution1.cpp"
#include "exponentiation_solution2.cpp"

using std::string;

TEST(exponentiation, test_n_k)
{
	for(int i = 0 ; i < 10 ; i++)
		for(int j = 0 ; j < 10 ; j++){
			EXPECT_EQ((unsigned)std::pow(i,j) , exponentiation_linear(i,j));
			EXPECT_EQ((unsigned)std::pow(i,j) , exponentiation_fast(i,j));

		}
		
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

