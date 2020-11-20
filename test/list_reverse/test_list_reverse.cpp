#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
#include "list.h"
using Book::List::Node;
#include "list_reverse_solution1.cpp"
#include "list_reverse_solution2.cpp"

template <typename T>
Node<T> *create_list_from(std::vector<int> &vec, const int loop = -1)
{
  using N = Node<T>;
  if (vec.size() <= 0)
    return nullptr;

  std::vector<N *> p;

  for (size_t i = 0; i < vec.size(); i++)
    p.push_back(new N(vec[i]));

  for (int i = 0; i < (int)p.size() - 1; i++)
    p[i]->next = p[i + 1];

  if (loop >= (int)vec.size())
    throw std::invalid_argument(
        "loop index is larger than the length of the list");

  if (loop != -1)
    p.back()->next = p[loop];
  return p[0];
}



TEST(list_reverse, example1)
{

  std::vector<int> v = {1, 2, 3, 4,5};
  Node<int> *head    = create_list_from<int>(v, -1);
  auto ans = list_reverse_linear_space(head);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

