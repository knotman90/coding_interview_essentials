#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "max_gap_solution1.cpp"
#include "max_gap_solution2.cpp"
#include "algorithm.h"

TEST(max_gap, test1)
{
	
	for(const auto&[input, expected] : 
    {
        std::pair<std::vector<int>, int>({1,2,3},1),
        std::pair<std::vector<int>, int>({5,3,1,8,9,2,4},3),
        std::pair<std::vector<int>, int>({7, 1, 8, 9,15},6),
    }
    ){
        
        EXPECT_EQ(expected, max_gap_bruteforce(input));

        EXPECT_EQ(expected, max_gap_radix_sort(input));
    }
}


TEST(max_gap, test_consistency_solutions)
{
	
	constexpr size_t num_tests = 100;
    constexpr size_t max_size_tests = 10000;
    for(int i = 0 ; i < num_tests ; i++)
    {
        const auto& input = Book::Algorithm::generate_random_vector_in_range(max_size_tests, 0, 10000);
     
        const auto& output1 = max_gap_bruteforce(input);
        const auto& output2 =  max_gap_radix_sort(input);
        ASSERT_EQ(output1, output2);
    
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

