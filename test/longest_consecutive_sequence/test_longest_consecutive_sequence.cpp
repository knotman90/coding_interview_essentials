#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "longest_consecutive_sequence_solution1.cpp"
#include "longest_consecutive_sequence_solution2.cpp"

#include "algorithm.h"

std::random_device rd;
std::mt19937 g(rd());


TEST(longest_consecutive_sequence, test_example_1)
{
    constexpr size_t expected = 4;
    const std::vector<int> base_input = {100,4,200,1,3,2};
	{
        int shuffles = 10;
        do{

            std::vector<int> input = base_input;
            const auto ans = longest_consecutive_sequence_sorting(input);
            EXPECT_EQ(expected,ans);
            std::shuffle(input.begin(), input.end(), g);
        }while(--shuffles > 0);
    }
}

TEST(longest_consecutive_sequence, test_example_2)
{
    constexpr size_t expected = 9;
    const std::vector<int> base_input = {0,3,7,2,5,8,4,6,0,1};
	{
        int shuffles = 10;
        do{

            std::vector<int> input = base_input;
            const auto ans = longest_consecutive_sequence_sorting(input);
            EXPECT_EQ(expected,ans);
            std::shuffle(input.begin(), input.end(), g);
        }while(--shuffles > 0);
    }
}


TEST(longest_consecutive_sequence, test_empty)
{
    constexpr size_t expected = 0;
    const std::vector<int> base_input = {};
	{
        int shuffles = 10;
        do{
            std::vector<int> input = base_input;
            const auto ans = longest_consecutive_sequence_sorting(input);
            EXPECT_EQ(expected,ans);
            std::shuffle(input.begin(), input.end(), g);
        }while(--shuffles > 0);
    }
}


TEST(longest_consecutive_sequence, test_single)
{
    constexpr size_t expected = 1;
    const std::vector<int> base_input = {1256};
	{
        int shuffles = 10;
        do{
            std::vector<int> input = base_input;
            const auto ans = longest_consecutive_sequence_sorting(input);
            EXPECT_EQ(expected,ans);
            std::shuffle(input.begin(), input.end(), g);
        }while(--shuffles > 0);
    }
}

TEST(longest_consecutive_sequence, test_two_elements_disjoints)
{
    constexpr size_t expected = 1;
    const std::vector<int> base_input = {125,123};
	{
        int shuffles = 10;
        do{

            std::vector<int> input = base_input;
            const auto ans = longest_consecutive_sequence_sorting(input);
            EXPECT_EQ(expected,ans);
            std::shuffle(input.begin(), input.end(), g);
        }while(--shuffles > 0);
    }
}

TEST(longest_consecutive_sequence, test_two_elements_consecutive)
{
    constexpr size_t expected = 2;
    const std::vector<int> base_input = {888,887};
	{
        int shuffles = 10;
        do{

            std::vector<int> input = base_input;
            const auto ans = longest_consecutive_sequence_sorting(input);
            EXPECT_EQ(expected,ans);
            std::shuffle(input.begin(), input.end(), g);
        }while(--shuffles > 0);
    }
}


TEST(longest_consecutive_sequence, test_100_consecutive)
{
    constexpr size_t expected = 100;
    const std::vector<int> base_input = {60,45,31,18,59,87,37,17,86,79,70,20,44,26,5,9,98,4,71,65,28,56,25,49,51,48,16,83,84,12,2,38,91,14,32,22,81,80,74,10,11,57,7,54,95,88,92,50,76,72,33,36,47,85,13,89,63,43,93,68,52,66,29,90,78,58,23,27,69,3,67,6,21,41,55,19,62,82,64,15,42,24,46,94,34,75,30,1,40,100,35,73,39,53,99,96,97,77,8,61};
	{
        int shuffles = 10;
        do{

            std::vector<int> input = base_input;
            const auto ans = longest_consecutive_sequence_sorting(input);
            EXPECT_EQ(expected,ans);
            std::shuffle(input.begin(), input.end(), g);
        }while(--shuffles > 0);
    }
}


TEST(longest_consecutive_sequence, test_100_repeated_twice_consecutive)
{
    constexpr size_t expected = 100;
    const std::vector<int> base_input = {60,45,31,18,59,87,37,17,86,79,70,20,44,26,5,9,98,4,71,65,28,56,25,49,51,48,16,83,84,12,2,38,91,14,32,22,81,80,74,10,11,57,7,54,95,88,92,50,76,72,33,36,47,85,13,89,63,43,93,68,52,66,29,90,78,58,23,27,69,3,67,6,21,41,55,19,62,82,64,15,42,24,46,94,34,75,60,45,31,18,59,87,37,17,86,79,70,20,44,26,5,9,98,4,71,65,28,56,25,49,51,48,16,83,84,12,2,38,91,14,32,22,81,80,74,10,11,57,7,54,95,88,92,50,76,72,33,36,47,85,13,89,63,43,93,68,52,66,29,90,78,58,23,27,69,3,67,6,21,41,55,19,62,82,64,15,42,24,46,94,34,75,30,1,40,100,35,73,39,53,99,96,97,77,8,61,30,1,40,100,35,73,39,53,99,96,97,77,8,61};
	{
        int shuffles = 10;
        do{

            std::vector<int> input = base_input;
            const auto ans = longest_consecutive_sequence_sorting(input);
            EXPECT_EQ(expected,ans);
            std::shuffle(input.begin(), input.end(), g);
        }while(--shuffles > 0);
    }
}


TEST(longest_consecutive_sequence, test_random_vector_100_elements_from_123_to_223)
{
    const std::vector<int> base_input = Book::Algorithm::generate_random_vector_in_range(100, 123,223);
    std::vector<size_t> solutions={};
    {
            std::vector<int> input = base_input;
            const auto ans = longest_consecutive_sequence_sorting(input);
        solutions.push_back(ans);
    }
    ASSERT_TRUE(solutions.size() > 1);
    for(const auto&sol : solutions){
        ASSERT_EQ(*solutions.begin(), sol);
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

