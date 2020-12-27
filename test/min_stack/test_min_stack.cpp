#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

#include "min_stack_solution1.cpp"
#include "min_stack_solution2.cpp"
#include "min_stack_solution3.cpp"

using op = std::pair<char, int>;

template <typename Stack>
auto execute_operation(const op& o, Stack& stack)
{
  const auto [c, v] = o;
  switch (c)
  {
      // Push
    case 'p':
    case 'P':
      stack.push(v);
      break;

      // Pop
    case 'r':
    case 'R':
      stack.pop();
      break;
      // Top
    case 't':
    case 'T':
      return stack.top();
      break;
      // min
    case 'm':
    case 'M':
      return stack.getMin();
      break;
  }
  return -1;
}

template <typename T>
class min_stack_fixture : public ::testing::Test
{
 public:
  T value_;
};

using min_stack_implementations =
    ::testing::Types<min_stack_stack_pair<int>,
                     min_stack_two_stacks<int>,
                     min_stack_int_constant_time<int>>;
TYPED_TEST_SUITE(min_stack_fixture, min_stack_implementations);

TYPED_TEST(min_stack_fixture, test_increasing)
{
  TypeParam stack_pair = this->value_;
  EXPECT_THROW(stack_pair.pop(), std::logic_error);
  EXPECT_THROW(stack_pair.top(), std::logic_error);
  EXPECT_THROW(stack_pair.getMin(), std::logic_error);

  constexpr int END   = 100;
  constexpr int START = 100;
  for (int i = START; i < END; i++)
  {
    const op o = {'p', i};
    EXPECT_NO_THROW(execute_operation(o, stack_pair));
    if (o.first == 'p')
    {
      EXPECT_EQ(o.second, stack_pair.top());
    }
    EXPECT_EQ(START, stack_pair.getMin());
  }

  // remove all
  for (int i = START; i < END; i++)
  {
    const op o = {'r', i};
    EXPECT_NO_THROW(execute_operation(o, stack_pair));
    EXPECT_EQ(END - 1 - i, stack_pair.top());

    EXPECT_EQ(START, stack_pair.getMin());
  }

  // empty again should throw
  EXPECT_THROW(stack_pair.pop(), std::logic_error);
  EXPECT_THROW(stack_pair.top(), std::logic_error);
  EXPECT_THROW(stack_pair.getMin(), std::logic_error);
}

TYPED_TEST(min_stack_fixture, test_decreasing)
{
  constexpr int END   = 100;
  constexpr int START = 0;
  min_stack_stack_pair<int> stack_pair;
  for (int i = END; i >= START; i--)
  {
    const op o = {'p', i};
    EXPECT_NO_THROW(execute_operation(o, stack_pair));
    if (o.first == 'p')
    {
      EXPECT_EQ(o.second, stack_pair.top());
    }
    EXPECT_EQ(o.second, stack_pair.getMin());
  }

  // remove all
  for (int i = START; i < END; i++)
  {
    const op o = {'r', i};
    EXPECT_EQ(i, stack_pair.top());
    EXPECT_EQ(stack_pair.top(), stack_pair.getMin());
    EXPECT_NO_THROW(execute_operation(o, stack_pair));

    EXPECT_EQ(i + 1, stack_pair.top());
    EXPECT_EQ(stack_pair.top(), stack_pair.getMin());
  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
