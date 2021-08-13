#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::swap;
using std::vector;

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

template <typename T>
Node<T> *create_list_from(std::vector<pair<T, int>> &vec)
{
  using N = Node<T>;
  if (vec.size() <= 0)
    return nullptr;

  std::vector<N *> p;

  for (int i = 0; i < vec.size(); i++)
    p.push_back(new N(vec[i].first));

  for (int i = 0; i < p.size() - 1; i++)
    p[i]->next = p[i + 1];

  for (int i = 0; i < vec.size(); i++)
    if (vec[i].second < -1 || vec[i].second >= (int)p.size())
      throw std::invalid_argument("invalid random pointer: "
                                  + std::to_string(vec[i].second));
    else if (vec[i].second != -1)
      p[i]->random = p[vec[i].second];

  return p[0];
}

template <typename T>
auto to_vector(const Node<T> *l1)
{
  map<const Node<T> *, int> P;
  vector<pair<T, int>> ans;

  int i            = 0;
  const Node<T> *l = l1;
  while (l)
  {
    P[l] = i;
    ans.push_back(std::make_pair(l->val, -1));
    i++;
    l = l->next;
  }

  i = 0;
  l = l1;
  while (l)
  {
    if (l->random)
      ans[i].second = P[l->random];
    i++;
    l = l->next;
  }

  return ans;
}

template <typename T>
bool equal(const Node<T> *const l1, const Node<T> *const l2)
{
  const auto lv1 = to_vector(l1);
  const auto lv2 = to_vector(l2);
  return lv1 == lv2;
}

template <typename T>
bool share_nodes(Node<T> *l1, Node<T> *l2)
{
  vector<Node<T> *> vec1;
  vector<Node<T> *> vec2;
  vector<Node<T> *> intersection;

  while (l1)
  {
    vec1.push_back(l1);
    l1 = l1->next;
  }
  while (l2)
  {
    vec2.push_back(l2);
    l2 = l2->next;
  }
  sort(begin(vec1), end(vec1));
  sort(begin(vec2), end(vec2));
  std::set_intersection(vec1.begin(),
                        vec1.end(),
                        vec2.begin(),
                        vec2.end(),
                        std::inserter(intersection, intersection.begin()));
  return intersection.size() > 0;
}

using Ni = Node<int>;
TEST(clone_list_random_pointer, test_empty)
{
  vector<pair<int, int>> lv = {};

  Ni *list  = create_list_from(lv);
  Ni *clone = clone_random_list_map(list);

  EXPECT_TRUE(equal(list, clone));
  EXPECT_FALSE(share_nodes(list, clone));

  Ni *clone1 = clone_random_list_interleave_lists(list);
  EXPECT_TRUE(equal(list, clone1));
  EXPECT_FALSE(share_nodes(list, clone1));
}

TEST(clone_list_random_pointer, test_no_random)
{
  vector<pair<int, int>> lv = {{0, -1},
                               {1, -1},
                               {2, -1},
                               {3, -1},
                               {4, -1},
                               {5, -1},
                               {6, -1},
                               {7, -1},
                               {8, -1},
                               {9, -1},
                               {10, -1}};

  Ni *list  = create_list_from(lv);
  Ni *clone = clone_random_list_map(list);

  EXPECT_TRUE(equal(list, clone));
  EXPECT_FALSE(share_nodes(list, clone));

  Ni *clone1 = clone_random_list_interleave_lists(list);
  EXPECT_TRUE(equal(list, clone1));
  EXPECT_FALSE(share_nodes(list, clone1));
}

TEST(clone_list_random_pointer, test_all_self)
{
  vector<pair<int, int>> lv = {{0, 0},
                               {1, 1},
                               {2, 2},
                               {3, 3},
                               {4, 4},
                               {5, 5},
                               {6, 6},
                               {7, 7},
                               {8, 8},
                               {9, 9},
                               {10, 10}};

  Ni *list  = create_list_from(lv);
  Ni *clone = clone_random_list_map(list);

  EXPECT_TRUE(equal(list, clone));
  EXPECT_FALSE(share_nodes(list, clone));

  Ni *clone1 = clone_random_list_interleave_lists(list);
  EXPECT_TRUE(equal(list, clone1));
  EXPECT_FALSE(share_nodes(list, clone1));
}

TEST(clone_list_random_pointer, test_all_next)
{
  vector<pair<int, int>> lv = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, -1}};

  Ni *list  = create_list_from(lv);
  Ni *clone = clone_random_list_map(list);

  EXPECT_TRUE(equal(list, clone));
  EXPECT_FALSE(share_nodes(list, clone));

  Ni *clone1 = clone_random_list_interleave_lists(list);
  EXPECT_TRUE(equal(list, clone1));
  EXPECT_FALSE(share_nodes(list, clone1));
}

TEST(clone_list_random_pointer, test_all_next_next_toroidal)
{
  vector<pair<int, int>> lv = {{0, 2}, {1, 3}, {2, 4}, {3, 0}, {4, 2}};

  Ni *list  = create_list_from(lv);
  Ni *clone = clone_random_list_map(list);

  EXPECT_TRUE(equal(list, clone));
  EXPECT_FALSE(share_nodes(list, clone));

  Ni *clone1 = clone_random_list_interleave_lists(list);
  EXPECT_TRUE(equal(list, clone1));
  EXPECT_FALSE(share_nodes(list, clone1));
}

TEST(clone_list_random_pointer, test_random)
{
  vector<pair<int, int>> lv = {{0, 10},
                               {1, 3},
                               {2, 8},
                               {3, 9},
                               {4, 8},
                               {5, 10},
                               {6, 8},
                               {7, 2},
                               {8, 1},
                               {9, 4},
                               {10, 10}};

  Ni *list  = create_list_from(lv);
  Ni *clone = clone_random_list_map(list);

  EXPECT_TRUE(equal(list, clone));
  EXPECT_FALSE(share_nodes(list, clone));

  Ni *clone1 = clone_random_list_interleave_lists(list);
  EXPECT_TRUE(equal(list, clone1));
  EXPECT_FALSE(share_nodes(list, clone1));
}

TEST(clone_list_random_pointer, test_random_100)
{
  vector<pair<int, int>> lv = {
      {0, 28},  {1, 33},  {2, 22},  {3, 47},  {4, 19},  {5, 41},  {6, 79},
      {7, 34},  {8, 85},  {9, 53},  {10, 55}, {11, 46}, {12, 48}, {13, 60},
      {14, 61}, {15, 23}, {16, 19}, {17, 46}, {18, 5},  {19, 6},  {20, 66},
      {21, 18}, {22, 23}, {23, 99}, {24, 35}, {25, 94}, {26, 10}, {27, 85},
      {28, 26}, {29, 39}, {30, 38}, {31, 83}, {32, 32}, {33, 63}, {34, 88},
      {35, 52}, {36, 60}, {37, 67}, {38, 75}, {39, 33}, {40, 97}, {41, 61},
      {42, 38}, {43, 51}, {44, 38}, {45, 83}, {46, 92}, {47, 45}, {48, 61},
      {49, 95}, {50, 94}, {51, 64}, {52, 50}, {53, 54}, {54, 32}, {55, 81},
      {56, 47}, {57, 47}, {58, 42}, {59, 61}, {60, 64}, {61, 40}, {62, 70},
      {63, 75}, {64, 42}, {65, 14}, {66, 27}, {67, 24}, {68, 64}, {69, 59},
      {70, 11}, {71, 3},  {72, 69}, {73, 73}, {74, 88}, {75, 31}, {76, 96},
      {77, 51}, {78, 21}, {79, 14}, {80, 25}, {81, 77}, {82, 72}, {83, 37},
      {84, 35}, {85, 96}, {86, 51}, {87, 27}, {88, 64}, {89, 48}, {90, 52},
      {91, 8},  {92, 15}, {93, 1},  {94, 83}, {95, 44}, {96, 81}, {97, 17},
      {98, 24}, {99, 68}, {100, 12}};

  Ni *list  = create_list_from(lv);
  Ni *clone = clone_random_list_map(list);

  EXPECT_TRUE(equal(list, clone));
  EXPECT_FALSE(share_nodes(list, clone));

  Ni *clone1 = clone_random_list_interleave_lists(list);
  EXPECT_TRUE(equal(list, clone1));
  EXPECT_FALSE(share_nodes(list, clone1));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
