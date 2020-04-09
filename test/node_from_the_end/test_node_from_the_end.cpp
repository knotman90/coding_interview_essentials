#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#include "node_from_the_end_solution1.cpp"
#include "node_from_the_end_solution2.cpp"

TEST(node_from_the_end, test1) { EXPECT_EQ(0, 1); }

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
