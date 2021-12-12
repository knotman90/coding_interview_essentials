#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "spiral_matrix_solution1.cpp"
#include "spiral_matrix_solution2.cpp"




TEST(spiral_matrix, test1)
{
	
	const std::vector<std::vector<int>> input = {
        {1,2,3,4},
        {10,11,12,5},
        {9,8,7,6},
        };

    const std::vector<int> expected = {1,2,3,4,5,6,7,8,9,10,11,12};
    const auto ans = spiral_matrix_solution(input);
    ASSERT_EQ(expected, ans);
}


TEST(spiral_matrix, test2)
{
	
	const std::vector<std::vector<int>> input = {
        {1,2,3,4},
        {5,6, 7, 8},
        {9,10,11,12},
        {13,14,15,16},
        };

    const std::vector<int> expected = {1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10};
    const auto ans = spiral_matrix_solution(input);
    ASSERT_EQ(expected, ans);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

