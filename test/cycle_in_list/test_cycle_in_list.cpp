#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;

template <typename T> struct Node
{
  T val;
  Node *next;
  Node(T x) : val(x), next(nullptr) {}
};


#include "cycle_in_list_solution1.cpp"
#include "cycle_in_list_solution2.cpp"




TEST(cycle_in_list, test1)
{
	
	EXPECT_EQ(0,1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

