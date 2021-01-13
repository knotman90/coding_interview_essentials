#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "decode_string_solution1.cpp"
#include "decode_string_solution2.cpp"

TEST(decode_string, test1)
{
  using TestInput = std::tuple<std::string, std::string>;

  for (const auto [input, expected] :
       {
           /*TestInput("2[abc]3[ab]", "abcabcababab"),
       TestInput("2[abc3[ab]]", "abcababababcababab"),
       TestInput("2[abc]3[cd]ef", "abcabccdcdcdef"),*/
       TestInput("start2[a3[b4[c2[d]e]f]g]end", "startabcddecddecddecddefbcddecddecddecddefbcddecddecddecddefgabcddecddecddecddefbcddecddecddecddefbcddecddecddecddefgend"),
       TestInput("10[ciao]", "ciaociaociaociaociaociaociaociaociaociao"),


       })
  {

      {
          auto ans = decode_string(input);
          EXPECT_EQ(expected, ans) << "failed for "<<input;
      }
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
