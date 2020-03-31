#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::begin;
using std::end;
using std::endl;

#include "min_rotated_array_solution1.cpp"
#include "min_rotated_array_solution2.cpp"




TEST(min_rotated_array, test_one_element_vector)
{
	const std::vector<int> V{1};
	EXPECT_EQ(1,min_rotated_array_brute_force(V));
	EXPECT_EQ(1,min_rotated_array_brute_force_1(V));
}

TEST(min_rotated_array, test_no_rotation_vector)
{
	const std::vector<int> V{1,2,3,4,5,6,7,8,9,10};
	EXPECT_EQ(1,min_rotated_array_brute_force(V));
	EXPECT_EQ(1,min_rotated_array_brute_force_1(V));
}

TEST(min_rotated_array, test_all_rotations)
{
	const std::vector<int> V_original{1,2,3,4,5,6,7,8,9,10};
	for(int i = 0 ; i < V_original.size() ; i++){
		std::vector<int> V(V_original);
		std::rotate(begin(V), begin(V)+i, end(V));
		EXPECT_EQ(1,min_rotated_array_brute_force(V));
		EXPECT_EQ(1,min_rotated_array_brute_force_1(V));
	}
}

TEST(min_rotated_array, test_all_rotations_negative)
{
	const std::vector<int> V_original{-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	for(int i = 0 ; i < V_original.size() ; i++){
		std::vector<int> V(V_original);
		std::rotate(begin(V), begin(V)+i, end(V));
		EXPECT_EQ(-10,min_rotated_array_brute_force(V));
		EXPECT_EQ(-10,min_rotated_array_brute_force_1(V));
	}
}





int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

