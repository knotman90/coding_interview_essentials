#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;

#include "sorted_array_union_solution1.cpp"
#include "sorted_array_union_solution2.cpp"




TEST(sorted_array_union, test_20_random)
{
	std::vector<int> A1= {6,9,13,16,19,23,35,37,49,57,61,62,71,72,75,83,86,93,96,99};
	std::vector<int> A2= {1,7,9,11,28,32,33,34,44,57,63,67,69,70,73,77,80,90,92,94};

	std::vector<int> expected(A1);
	std::copy(begin(A2), end(A2),  std::back_inserter(expected));

	EXPECT_EQ(expected, sorted_arrays_union_naive(A1,A2));
	
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

