#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "LRU_cache_solution1.cpp"
#include "LRU_cache_solution2.cpp"
#include "LRU_cache_solution3.cpp"

enum Operation
{
  Insert,
  Get
};

using TestUnit = std::tuple<Operation, std::string>;
template <typename Cache>
std::vector<std::optional<int>> exerciseCache(Cache& cache,
                                              const vector<TestUnit>& input)
{
  std::vector<std::optional<int>> ans{};
  for (const auto& [operation, str] : input)
  {
    if (operation == Insert)
    {
      int key, value;
      sscanf(str.c_str(), "%d %d", &key, &value);
      cache.put(key, value);
      ans.push_back(std::nullopt);
    }
    else if (operation == Get)
    {
      int key;
      sscanf(str.c_str(), "%d", &key);
      const auto x = cache.get(key);
      ans.push_back(x);
    }
    else
    {
      throw "Invalid Operation";
    }
  }
  return ans;
  assert(input.size() == ans.size());
}

class TimeOuttedTest : public testing::Test
{
 protected:
  // Remember that SetUp() is run immediately before a test starts.
  // This is a good place to record the start time.
  void SetUp() override
  {
    start_time_ = time(nullptr);
  }

  // TearDown() is invoked immediately after a test finishes.  Here we
  // check if the test was too slow.
  void TearDown() override
  {
    // Gets the time when the test finishes
    const time_t end_time = time(nullptr);

    // Asserts that the test took no more than ~5 seconds.  Did you
    // know that you can use assertions in SetUp() and TearDown() as
    // well?
    EXPECT_TRUE(end_time - start_time_ <= 2) << "The test took too long.";
  }
  // The UTC time (in seconds) when the test starts
  time_t start_time_;
};

template <typename Cache>
class LRUCacheTest : public TimeOuttedTest
{
 public:
  void givenCache(Cache& aCache)
  {
    cache = aCache;
  }
  void givenInput(const std::vector<TestUnit>& aInput)
  {
    input = aInput;
  }

  void expectCacheToReturn(const std::vector<std::optional<int>>& aExpected)
  {
    expected = aExpected;
    ans      = exerciseCache(cache, input);
    EXPECT_EQ(expected.size(), ans.size());
    for (size_t i = 0; i < ans.size(); ++i)
    {
      EXPECT_EQ(expected[i], ans[i]) << "Vectors x and y differ at index " << i;
    }
  }

 private:
  Cache cache;
  std::vector<TestUnit> input;
  std::vector<std::optional<int>> expected, ans;
};

using LRUCacheTestSolution1 = LRUCacheTest<LRUCache_solution1>;

TEST_F(LRUCacheTestSolution1, Solution1_basicTest1)
{
  constexpr size_t kCapacity = 2;
  LRUCache_solution1 cache1(kCapacity);
  givenCache(cache1);
  givenInput(std::vector<TestUnit>{{Insert, "1 50"}, {Get, "1"}});
  expectCacheToReturn(std::vector<std::optional<int>>{{}, {50}});
}

TEST_F(LRUCacheTestSolution1, Solution1_basicTest_not_preset)
{
  constexpr size_t kCapacity = 2;
  LRUCache_solution1 cache1(kCapacity);
  givenCache(cache1);
  givenInput(std::vector<TestUnit>{{Insert, "1 50"}, {Get, "2"}});
  expectCacheToReturn(std::vector<std::optional<int>>{{}, {}});
}

TEST_F(LRUCacheTestSolution1, Solution1_basic_overflow_capacity)
{
  constexpr size_t kCapacity = 2;
  LRUCache_solution1 cache1(kCapacity);
  givenCache(cache1);
  givenInput(std::vector<TestUnit>{{Insert, "1 1"},
                                   {Insert, "2 2"},
                                   {Get, "1"},
                                   {Get, "2"},
                                   {Insert, "3 3"},
                                   {Get, "1"},
                                   {Get, "2"},
                                   {Get, "3"}});
  expectCacheToReturn(
      std::vector<std::optional<int>>{{},
                                      {},
                                      {1},
                                      {2},
                                      {},
                                      {},  // 1 is eviced by insert 3,3
                                      {2},
                                      {3}});
}

using LRUCacheTestSolutionlogn = LRUCacheTest<LRUCache_logn<int, int>>;

TEST_F(LRUCacheTestSolutionlogn, Solution1_basicTest1)
{
  constexpr size_t kCapacity = 2;
  LRUCache_logn<int, int> cache1(kCapacity);
  givenCache(cache1);
  givenInput(std::vector<TestUnit>{{Insert, "1 50"}, {Get, "1"}});
  expectCacheToReturn(std::vector<std::optional<int>>{{}, {50}});
}

TEST_F(LRUCacheTestSolutionlogn, Solution1_basicTest_not_preset)
{
  constexpr size_t kCapacity = 2;
  LRUCache_logn<int, int> cache1(kCapacity);
  givenCache(cache1);
  givenInput(std::vector<TestUnit>{{Insert, "1 50"}, {Get, "2"}});
  expectCacheToReturn(std::vector<std::optional<int>>{{}, {}});
}

TEST_F(LRUCacheTestSolutionlogn, Solution1_basic_overflow_capacity)
{
  constexpr size_t kCapacity = 2;
  LRUCache_logn<int, int> cache1(kCapacity);
  givenCache(cache1);
  givenInput(std::vector<TestUnit>{{Insert, "1 1"},
                                   {Insert, "2 2"},
                                   {Get, "1"},
                                   {Get, "2"},
                                   {Insert, "3 3"},
                                   {Get, "1"},
                                   {Get, "2"},
                                   {Get, "3"}});
  expectCacheToReturn(
      std::vector<std::optional<int>>{{},
                                      {},
                                      {1},
                                      {2},
                                      {},
                                      {},  // 1 is eviced by insert 3,3
                                      {2},
                                      {3}});
}

using LRUCacheTestSolutionlogn_implementation2 = LRUCacheTest<LRUCache_logn2>;

TEST_F(LRUCacheTestSolutionlogn_implementation2, Solution1_basicTest1)
{
  constexpr size_t kCapacity = 2;
  LRUCache_logn2 cache1(kCapacity);
  givenCache(cache1);
  givenInput(std::vector<TestUnit>{{Insert, "1 50"}, {Get, "1"}});
  expectCacheToReturn(std::vector<std::optional<int>>{{}, {50}});
}

TEST_F(LRUCacheTestSolutionlogn_implementation2, Solution1_basicTest_not_preset)
{
  constexpr size_t kCapacity = 2;
  LRUCache_logn2 cache1(kCapacity);
  givenCache(cache1);
  givenInput(std::vector<TestUnit>{{Insert, "1 50"}, {Get, "2"}});
  expectCacheToReturn(std::vector<std::optional<int>>{{}, {}});
}

TEST_F(LRUCacheTestSolutionlogn_implementation2,
       Solution1_basic_overflow_capacity)
{
  constexpr size_t kCapacity = 2;
  LRUCache_logn2 cache1(kCapacity);
  givenCache(cache1);
  givenInput(std::vector<TestUnit>{{Insert, "1 1"},
                                   {Insert, "2 2"},
                                   {Get, "1"},
                                   {Get, "2"},
                                   {Insert, "3 3"},
                                   {Get, "1"},
                                   {Get, "2"},
                                   {Get, "3"}});
  expectCacheToReturn(
      std::vector<std::optional<int>>{{},
                                      {},
                                      {1},
                                      {2},
                                      {},
                                      {},  // 1 is eviced by insert 3,3
                                      {2},
                                      {3}});
}

auto get_random_operations_sequence(const int size)
{
  std::vector<TestUnit> ans;
  for (int i = 0; i < size; i++)
  {
    auto isGet = (rand() % 2) == 0;
    TestUnit unit;
    if (isGet)
    {
      std::get<0>(unit) = Get;
      auto n            = rand() % size;
      std::get<1>(unit) = std::to_string(n);
      ans.push_back(unit);
    }
    else
    {
      std::get<0>(unit) = Insert;
      auto n            = rand() % size;
      auto n1           = rand() % size;
      std::get<1>(unit) = std::to_string(n) + " " + std::to_string(n1);
      ans.push_back(unit);
    }
  }
  return ans;
}

std::string sequence_to_string(auto input)
{
  std::ostringstream ss;
  ss << '{';
  for (const auto u : input)
  {
    ss << '{';
    ss << (!std::get<0>(u) ? "Insert" : "Get");
    ss << " , ";
    ss << std::get<1>(u);
    ss << "}, ";
  }
  ss << '}';
  return ss.str();
}

TEST(LRUCacheTest, random_all_solution)
{
  auto maxsize = 100000;
  for (int i = 0; i < 100; i++)
  {
    auto size     = (rand() % maxsize) + 1;
    auto capacity = (rand() % size) + 1;
    auto input    = get_random_operations_sequence(size);

    LRUCache_logn<int, int> cache1(capacity);
    auto ans1 = exerciseCache(cache1, input);

    LRUCache_logn2 cache2(capacity);
    auto ans2 = exerciseCache(cache2, input);

    LRUCache_solution1 cache3(capacity);
    auto ans3 = exerciseCache(cache3, input);

    ASSERT_EQ(ans1.size(), ans2.size())
        << "error on cap = " << capacity << " " << sequence_to_string(input);
    ASSERT_EQ(ans1.size(), ans3.size())
        << "error on cap = " << capacity << " " << sequence_to_string(input);
    ;
    for (int i = 0; i < ans1.size(); i++)
    {
      ASSERT_EQ(ans1[i], ans3[i])
          << "error on cap = " << capacity << " " << sequence_to_string(input);
      ;
      ASSERT_EQ(ans2[i], ans3[i])
          << "error on cap = " << capacity << " " << sequence_to_string(input);
      ;
    }
  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
