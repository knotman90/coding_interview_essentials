#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;

template<typename T>
struct Node {
     int val;
     Node<T> *left;
     Node<T> *right;
     Node<T>(int x) : val(x), left(nullptr), right(nullptr) {}
 };

#include "tree_diameter_solution1.cpp"
#include "tree_diameter_solution2.cpp"




TEST(tree_diameter, test1)
{
	
	EXPECT_EQ(0,1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

