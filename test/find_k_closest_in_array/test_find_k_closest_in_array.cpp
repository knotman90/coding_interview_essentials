#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "find_k_closest_in_array_solution1.cpp"
#include "find_k_closest_in_array_solution2.cpp"
#include "find_k_closest_in_array_solution3.cpp"

// source not in the book. used to test my_lower_bound
#include "find_k_closest_in_array_solution4.cpp"

TEST(find_k_closest_in_array, example1)
{
  std::vector<int> original = {1, 2, 3, 4, 5};
  const int k               = 4;
  const int x               = 4;

  const std::vector<int> expected = {2, 3, 4, 5};

  {
    std::vector<int> I = original;
    const std::vector<int> ans =
        kth_closest_in_array_binary_search_lower_bound(I, k, x);
    ASSERT_EQ(expected, ans);
  }

  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_my_lower_bound(I, k, x);
    ASSERT_EQ(expected, ans);
  }

  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_sorting(I, k, x);
    ASSERT_EQ(expected, ans);
  }
  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_partial_sorting(I, k, x);
    ASSERT_EQ(expected, ans);
  }
}

TEST(find_k_closest_in_array, example2)
{
  std::vector<int> original = {1, 2, 3, 4, 5};
  const int k               = 4;
  const int x               = 3;

  const std::vector<int> expected = {1, 2, 3, 4};

  {
    std::vector<int> I = original;
    const std::vector<int> ans =
        kth_closest_in_array_binary_search_lower_bound(I, k, x);
    ASSERT_EQ(expected, ans);
  }
  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_my_lower_bound(I, k, x);
    ASSERT_EQ(expected, ans);
  }
  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_sorting(I, k, x);
    ASSERT_EQ(expected, ans);
  }
  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_partial_sorting(I, k, x);
    ASSERT_EQ(expected, ans);
  }
}

TEST(find_k_closest_in_array, example3)
{
  std::vector<int> original = {
      12, 16, 26, 30, 35, 39, 42, 46, 48, 50, 53, 55, 56};
  const int k = 5;
  const int x = 36;

  const std::vector<int> expected = {26, 30, 35, 39, 42};

  {
    std::vector<int> I = original;
    const std::vector<int> ans =
        kth_closest_in_array_binary_search_lower_bound(I, k, x);
    ASSERT_EQ(expected, ans);
  }
  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_my_lower_bound(I, k, x);
    ASSERT_EQ(expected, ans);
  }
  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_sorting(I, k, x);
    ASSERT_EQ(expected, ans);
  }
  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_partial_sorting(I, k, x);
    ASSERT_EQ(expected, ans);
  }
}

TEST(find_k_closest_in_array, test1)
{
  std::vector<int> original = {
      12, 16, 26, 30, 35, 39, 42, 46, 48, 50, 53, 55, 56};
  const int k = 1;
  const int x = 56;

  const std::vector<int> expected = {56};

  {
    std::vector<int> I = original;
    const std::vector<int> ans =
        kth_closest_in_array_binary_search_lower_bound(I, k, x);
    ASSERT_EQ(expected, ans);
  }
  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_my_lower_bound(I, k, x);
    ASSERT_EQ(expected, ans);
  }
  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_sorting(I, k, x);
    ASSERT_EQ(expected, ans);
  }
  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_partial_sorting(I, k, x);
    ASSERT_EQ(expected, ans);
  }
}

TEST(find_k_closest_in_array, test2)
{
  std::vector<int> original = {
      12, 16, 26, 30, 35, 39, 42, 46, 48, 50, 53, 55, 56};
  const int k = 1;
  const int x = 12;

  const std::vector<int> expected = {12};

  {
    std::vector<int> I = original;
    const std::vector<int> ans =
        kth_closest_in_array_binary_search_lower_bound(I, k, x);
    ASSERT_EQ(expected, ans);
  }

  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_sorting(I, k, x);
    ASSERT_EQ(expected, ans);
  }
  {
    std::vector<int> I         = original;
    const std::vector<int> ans = kth_closest_in_array_partial_sorting(I, k, x);
    ASSERT_EQ(expected, ans);
  }
}

TEST(find_k_closest_in_array, test3)
{
  std::vector<int> original = {
      12, 16, 26, 30, 35, 39, 42, 46, 48, 50, 53, 55, 56};

  for (auto v : {
           std::make_tuple<std::vector<int>, int, int>({12}, 1, 13),
           std::make_tuple<std::vector<int>, int, int>({12}, 1, 14),
           std::make_tuple<std::vector<int>, int, int>({16}, 1, 15),
           std::make_tuple<std::vector<int>, int, int>({12, 16}, 2, 13),
           std::make_tuple<std::vector<int>, int, int>({12, 16}, 2, 14),
           std::make_tuple<std::vector<int>, int, int>({12, 16}, 2, 15),
           std::make_tuple<std::vector<int>, int, int>({12, 16, 26}, 3, 20),
           std::make_tuple<std::vector<int>, int, int>({16, 26, 30}, 3, 25),
           std::make_tuple<std::vector<int>, int, int>({53, 55, 56}, 3, 56),
           std::make_tuple<std::vector<int>, int, int>({53, 55, 56}, 3, 154),
           std::make_tuple<std::vector<int>, int, int>(
               {12, 16, 26, 30}, 4, -154),
           std::make_tuple<std::vector<int>, int, int>({50, 53, 55, 56}, 4, 55),
           std::make_tuple<std::vector<int>, int, int>({50, 53, 55, 56}, 4, 54),
       })
  {
    auto [expected, k, x] = v;

    {
      std::vector<int> I = original;
      const std::vector<int> ans =
          kth_closest_in_array_binary_search_lower_bound(I, k, x);
      ASSERT_EQ(expected, ans) << "failed for " << x;
    }
    {
      std::vector<int> I         = original;
      const std::vector<int> ans = kth_closest_in_array_my_lower_bound(I, k, x);
      ASSERT_EQ(expected, ans);
    }

    {
      std::vector<int> I         = original;
      const std::vector<int> ans = kth_closest_in_array_sorting(I, k, x);
      ASSERT_EQ(expected, ans);
    }
    {
      std::vector<int> I = original;
      const std::vector<int> ans =
          kth_closest_in_array_partial_sorting(I, k, x);
      ASSERT_EQ(expected, ans);
    }
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
