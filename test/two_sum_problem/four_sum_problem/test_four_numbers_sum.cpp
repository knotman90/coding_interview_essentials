#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "four_number_sum_solution1.cpp"
#include "four_number_sum_solution2.cpp"
#include "four_number_sum_solution3.cpp"
#include "four_number_sum_solution4.cpp"

#include "algorithm.h"

TEST(four_numbers_sum_problem, test1)
{
  std::vector<std::vector<int>> inputs = {
      {1, 2},
      {-2, -1},
      {-1, 2},
      {0, 2},
  };
  for (const auto [T, expected] : {
           std::pair<int, int>(0, 2),
       })
  {
    {
      {
        auto inputs_copy = inputs;
        ASSERT_EQ(
            expected,
            four_sum_bruteforce(
                inputs.at(0), inputs.at(1), inputs.at(2), inputs.at(3), T));
      }

      {
        auto inputs_copy = inputs;
        ASSERT_EQ(
            expected,
            four_sum_cubic(
                inputs.at(0), inputs.at(1), inputs.at(2), inputs.at(3), T));
      }

      {
        auto inputs_copy = inputs;
        ASSERT_EQ(
            expected,
            four_sum_hashing(
                inputs.at(0), inputs.at(1), inputs.at(2), inputs.at(3), T));
      }

      {
        auto inputs_copy = inputs;
        ASSERT_EQ(
            expected,
            four_sum_hashing_space_optimized(
                inputs.at(0), inputs.at(1), inputs.at(2), inputs.at(3), T));
      }
    }
  }
}

TEST(four_numbers_sum_problem, test_consistency_solutions)
{
  constexpr size_t num_tests      = 10;
  constexpr size_t max_size_tests = 20;
  constexpr int m                 = -50;
  constexpr int M                 = 50;
  for (size_t i = 0; i < num_tests; i++)
  {
    for (int k = 0; k <= 10; k++)
    {
      const int T = Book::Algorithm::get_random_in_range(-m * 5, M * 5);

      std::vector<std::vector<int>> inputs = {
          Book::Algorithm::generate_random_vector_in_range(
              max_size_tests, m, M),
          Book::Algorithm::generate_random_vector_in_range(
              max_size_tests, m, M),
          Book::Algorithm::generate_random_vector_in_range(
              max_size_tests, m, M),
          Book::Algorithm::generate_random_vector_in_range(
              max_size_tests, m, M),
      };

      int output1 = 0;
      int output2 = 0;
      int output3 = 0;
      int output4 = 0;

      {
        auto inputs_copy = inputs;

        output1 = four_sum_bruteforce(
            inputs.at(0), inputs.at(1), inputs.at(2), inputs.at(3), T);
      }

      {
        auto inputs_copy = inputs;

        output2 = four_sum_bruteforce(
            inputs.at(0), inputs.at(1), inputs.at(2), inputs.at(3), T);
      }

      {
        auto inputs_copy = inputs;

        output3 = four_sum_bruteforce(
            inputs.at(0), inputs.at(1), inputs.at(2), inputs.at(3), T);
      }

      {
        auto inputs_copy = inputs;

        output4 = four_sum_bruteforce(
            inputs.at(0), inputs.at(1), inputs.at(2), inputs.at(3), T);
      }

      ASSERT_EQ(output1, output2);
      ASSERT_EQ(output2, output3);
      ASSERT_EQ(output3, output4);
    }
  }
}
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
