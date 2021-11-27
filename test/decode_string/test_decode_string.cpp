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

  for (const auto [input, expected] : {
           /*TestInput("2[abc]3[ab]", "abcabcababab"),
       TestInput("2[abc3[ab]]", "abcababababcababab"),
       TestInput("2[abc]3[cd]ef", "abcabccdcdcdef"),*/
           TestInput(
               "start2[a3[b4[c2[d]e]f]g]end",
               "startabcddecddecddecddefbcddecddecddecddefbcddecddecddecddefgab"
               "cddecddecddecddefbcddecddecddecddefbcddecddecddecddefgend"),
           TestInput("10[ciao]", "ciaociaociaociaociaociaociaociaociaociao"),
           TestInput(
               "1[a2[b3[c4[de]]]]",
               "abcdedededecdedededecdedededebcdedededecdedededecdededede"),
           TestInput(
               "1[a2[b1[c2[d1[e2[f1[g2[h1[i2[j1[k2[l1[m2[n1[o2[p1[q2[r1[s2[tu]]"
               "]]]]]]]]]]]]]]]]]]",
               "abcdefghijklmnopqrstuturstutupqrstuturstutunopqrstuturstutupqrs"
               "tuturstutulmnopqrstuturstutupqrstuturstutunopqrstuturstutupqrst"
               "uturstutujklmnopqrstuturstutupqrstuturstutunopqrstuturstutupqrs"
               "tuturstutulmnopqrstuturstutupqrstuturstutunopqrstuturstutupqrst"
               "uturstutuhijklmnopqrstuturstutupqrstuturstutunopqrstuturstutupq"
               "rstuturstutulmnopqrstuturstutupqrstuturstutunopqrstuturstutupqr"
               "stuturstutujklmnopqrstuturstutupqrstuturstutunopqrstuturstutupq"
               "rstuturstutulmnopqrstuturstutupqrstuturstutunopqrstuturstutupqr"
               "stuturstutufghijklmnopqrstuturstutupqrstuturstutunopqrstuturstu"
               "tupqrstuturstutulmnopqrstuturstutupqrstuturstutunopqrstuturstut"
               "upqrstuturstutujklmnopqrstuturstutupqrstuturstutunopqrstuturstu"
               "tupqrstuturstutulmnopqrstuturstutupqrstuturstutunopqrstuturstut"
               "upqrstuturstutuhijklmnopqrstuturstutupqrstuturstutunopqrstuturs"
               "tutupqrstuturstutulmnopqrstuturstutupqrstuturstutunopqrstuturst"
               "utupqrstuturstutujklmnopqrstuturstutupqrstuturstutunopqrstuturs"
               "tutupqrstuturstutulmnopqrstuturstutupqrstuturstutunopqrstuturst"
               "utupqrstuturstutudefghijklmnopqrstuturstutupqrstuturstutunopqrs"
               "tuturstutupqrstuturstutulmnopqrstuturstutupqrstuturstutunopqrst"
               "uturstutupqrstuturstutujklmnopqrstuturstutupqrstuturstutunopqrs"
               "tuturstutupqrstuturstutulmnopqrstuturstutupqrstuturstutunopqrst"
               "uturstutupqrstuturstutuhijklmnopqrstuturstutupqrstuturstutunopq"
               "rstuturstutupqrstuturstutulmnopqrstuturstutupqrstuturstutunopqr"
               "stuturstutupqrstuturstutujklmnopqrstuturstutupqrstuturstutunopq"
               "rstuturstutupqrstuturstutulmnopqrstuturstutupqrstuturstutunopqr"
               "stuturstutupqrstuturstutufghijklmnopqrstuturstutupqrstuturstutu"
               "nopqrstuturstutupqrstuturstutulmnopqrstuturstutupqrstuturstutun"
               "opqrstuturstutupqrstuturstutujklmnopqrstuturstutupqrstuturstutu"
               "nopqrstuturstutupqrstuturstutulmnopqrstuturstutupqrstuturstutun"
               "opqrstuturstutupqrstuturstutuhijklmnopqrstuturstutupqrstuturstu"
               "tunopqrstuturstutupqrstuturstutulmnopqrstuturstutupqrstuturstut"
               "unopqrstuturstutupqrstuturstutujklmnopqrstuturstutupqrstuturstu"
               "tunopqrstuturstutupqrstuturstutulmnopqrstuturstutupqrstuturstut"
               "unopqrstuturstutupqrstuturstutubcdefghijklmnopqrstuturstutupqrs"
               "tuturstutunopqrstuturstutupqrstuturstutulmnopqrstuturstutupqrst"
               "uturstutunopqrstuturstutupqrstuturstutujklmnopqrstuturstutupqrs"
               "tuturstutunopqrstuturstutupqrstuturstutulmnopqrstuturstutupqrst"
               "uturstutunopqrstuturstutupqrstuturstutuhijklmnopqrstuturstutupq"
               "rstuturstutunopqrstuturstutupqrstuturstutulmnopqrstuturstutupqr"
               "stuturstutunopqrstuturstutupqrstuturstutujklmnopqrstuturstutupq"
               "rstuturstutunopqrstuturstutupqrstuturstutulmnopqrstuturstutupqr"
               "stuturstutunopqrstuturstutupqrstuturstutufghijklmnopqrstuturstu"
               "tupqrstuturstutunopqrstuturstutupqrstuturstutulmnopqrstuturstut"
               "upqrstuturstutunopqrstuturstutupqrstuturstutujklmnopqrstuturstu"
               "tupqrstuturstutunopqrstuturstutupqrstuturstutulmnopqrstuturstut"
               "upqrstuturstutunopqrstuturstutupqrstuturstutuhijklmnopqrstuturs"
               "tutupqrstuturstutunopqrstuturstutupqrstuturstutulmnopqrstuturst"
               "utupqrstuturstutunopqrstuturstutupqrstuturstutujklmnopqrstuturs"
               "tutupqrstuturstutunopqrstuturstutupqrstuturstutulmnopqrstuturst"
               "utupqrstuturstutunopqrstuturstutupqrstuturstutudefghijklmnopqrs"
               "tuturstutupqrstuturstutunopqrstuturstutupqrstuturstutulmnopqrst"
               "uturstutupqrstuturstutunopqrstuturstutupqrstuturstutujklmnopqrs"
               "tuturstutupqrstuturstutunopqrstuturstutupqrstuturstutulmnopqrst"
               "uturstutupqrstuturstutunopqrstuturstutupqrstuturstutuhijklmnopq"
               "rstuturstutupqrstuturstutunopqrstuturstutupqrstuturstutulmnopqr"
               "stuturstutupqrstuturstutunopqrstuturstutupqrstuturstutujklmnopq"
               "rstuturstutupqrstuturstutunopqrstuturstutupqrstuturstutulmnopqr"
               "stuturstutupqrstuturstutunopqrstuturstutupqrstuturstutufghijklm"
               "nopqrstuturstutupqrstuturstutunopqrstuturstutupqrstuturstutulmn"
               "opqrstuturstutupqrstuturstutunopqrstuturstutupqrstuturstutujklm"
               "nopqrstuturstutupqrstuturstutunopqrstuturstutupqrstuturstutulmn"
               "opqrstuturstutupqrstuturstutunopqrstuturstutupqrstuturstutuhijk"
               "lmnopqrstuturstutupqrstuturstutunopqrstuturstutupqrstuturstutul"
               "mnopqrstuturstutupqrstuturstutunopqrstuturstutupqrstuturstutujk"
               "lmnopqrstuturstutupqrstuturstutunopqrstuturstutupqrstuturstutul"
               "mnopqrstuturstutupqrstuturstutunopqrstuturstutupqrstuturstutu"),

       })
  {
    {
      auto ans = decode_string(input);
      EXPECT_EQ(expected, ans) << "failed for " << input;
    }

    {
      auto ans = decode_string_recursive(input);
      EXPECT_EQ(expected, ans) << "failed for " << input;
    }
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
