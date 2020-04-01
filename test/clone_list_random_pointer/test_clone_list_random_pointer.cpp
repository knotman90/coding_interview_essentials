#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

template <class T> 
class Node
{
    public:
  T val;
  Node *next;
  Node *random;

  Node(const T &_val)
  {
    val    = _val;
    next   = nullptr;
    random = nullptr;
  }
};

#include "clone_list_random_pointer_solution1.cpp"
#include "clone_list_random_pointer_solution2.cpp"


TEST(clone_list_random_pointer, test1) { EXPECT_EQ(0, 1); }

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
