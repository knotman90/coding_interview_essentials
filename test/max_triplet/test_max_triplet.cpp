#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "algorithm.h"

#include "max_triplet_solution1.cpp"
#include "max_triplet_solution2.cpp"

std::string printCollection(const auto& collection)
{
    std::ostringstream ss;
    ss<<"{";
    for(const auto e : collection){
        ss<<e<<",";
    }
    ss<<"}";
    ss<<std::endl;
    return ss.str();
}


TEST(max_triplet, example1)
{
  for (auto [input, expected] : {
           std::pair<std::vector<int>, int>({2, 5, 3, 1, 4, 9}, 16),
           std::pair<std::vector<int>, int>({3, 2, 1}, -1),
           std::pair<std::vector<int>, int>({1, 3, 2}, -1),
           std::pair<std::vector<int>, int>({1, 2, 3}, 6),
           std::pair<std::vector<int>, int>({1, 2, 3, 4, 5, 6}, 15),
           std::pair<std::vector<int>, int>(
               {78, 95, 100, 73, 37, 84, 71, 68, 53, 39, 57, 82, 75, 55, 4,
                80, 33, 59,  18, 93, 44, 6,  19, 12, 69, 58, 97, 1,  99, 40,
                67, 46, 29,  30, 50, 79, 70, 31, 2,  17, 61, 24, 72, 98, 54,
                92, 64, 47,  62, 89, 11, 3,  86, 10, 66, 5,  74, 22, 91, 32,
                87, 21, 90,  23, 35, 49, 43, 13, 52, 60, 14, 41, 76, 77, 20,
                16, 85, 25,  81, 26, 88, 56, 42, 34, 51, 36, 28, 9,  65, 94,
                27, 45, 8,   15, 7,  38, 83, 48, 96, 63},
               291),
       })
  {
    auto ans = max_triplet_sum_bruteforce(input);
    ASSERT_EQ(expected, ans);
  }
}




TEST(max_triplet, random)
{
    for(int i = 0 ; i < 100 ; i++)
    {
        const int size = Book::Algorithm::get_random_in_range(1,200);
        const int l = Book::Algorithm::get_random_in_range(0,2000);
        const int r = Book::Algorithm::get_random_in_range(l,l+1000);
        const auto input = Book::Algorithm::generateRandomCollection<int>(size,l,r);

        const std::vector<int> answers = {
            max_triplet_sum_bruteforce(input),
            max_triplet_sum_prefix_binary_search(input),
        };

        ASSERT_TRUE(
            std::ranges::all_of(answers, [&](const auto& el){
            return el==answers[0];
            })
        ) <<"failed for "<< printCollection(input)
        << "answers are:" <<printCollection(answers);
    }
}



int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
