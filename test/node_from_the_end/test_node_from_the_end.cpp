#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

#include "list.h"

using Book::List::Node;

using ListNode = Node<int>;

#include "node_from_the_end_solution1.cpp"
#include "node_from_the_end_solution2.cpp"

class node_from_end_fixture : public ::testing::Test
{
 protected:
  ListNode* head = nullptr;
  std::vector<ListNode> nodes;

 public:
  void given_list_of(std::vector<int> vals)
  {
    assert(vals.size() > 0);

    nodes.clear();
    head = nullptr;
    nodes.resize(vals.size());
    for (size_t i = 0; i < nodes.size(); i++)
    {
      nodes[i].val = vals[i];
      if (i < nodes.size() - 1)
        nodes[i].next = &nodes[i + 1];
    }
    head = &nodes[0];
  }
};

TEST_F(node_from_end_fixture, given_list_with_one_element_remove_the_head)
{
  std::vector<int> vals = { 1 };
  given_list_of(vals);
  const int n = 0;

  ListNode* ans;
  EXPECT_NO_THROW(ans = remove_nth_node_from_end_bruteforce(head, n));
  EXPECT_EQ(nullptr, ans);

  ListNode* ans_two_pointers;
  EXPECT_NO_THROW(ans_two_pointers = remove_nth_node_from_end_bruteforce(head, n));
  EXPECT_EQ(nullptr, ans_two_pointers);
}

TEST_F(node_from_end_fixture, given_a_list_with_l_elements_remove_all)
{
  const std::vector<int> vals = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  for (size_t i = 0; i < vals.size(); i++)
  {
    given_list_of(vals);
    const int n               = 0;
    std::vector<int> expected = { vals };
    expected.erase(expected.begin() + expected.size() - 1 - n);
    {
      ListNode* ans;
      EXPECT_NO_THROW(ans = remove_nth_node_from_end_bruteforce(head, n));
      EXPECT_NE(nullptr, ans);
      EXPECT_EQ(expected, Book::List::to_vector(ans));
    }
    {
      given_list_of(vals);
      ListNode* ans_two_pointers;
      EXPECT_NO_THROW(ans_two_pointers = remove_nth_node_from_end_bruteforce(head, n));
      EXPECT_NE(nullptr, ans_two_pointers);
      EXPECT_EQ(expected, Book::List::to_vector(ans_two_pointers));
    }
  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
