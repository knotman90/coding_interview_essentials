#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "LRU_cache_solution1.cpp"
#include "LRU_cache_solution2.cpp"




enum Operation {Insert, Get};



using TestUnit = std::tuple<Operation, std::string>;
template<typename Cache>
std::vector<std::optional<int>> exerciseCache(Cache& cache, const vector<TestUnit>& input)
{
   std::vector<std::optional<int>> ans{};
   for(const auto& [operation, str] : input){
       if(operation== Insert){
           int key,value;
           sscanf(str.c_str(), "%d %d", &key, &value);
           cache.put(key, value);
           ans.push_back(std::nullopt);
       }else if (operation==Get)
       {
           int key;
           sscanf(str.c_str(), "%d", &key);
           const auto x = cache.get(key);
           ans.push_back(x);
       }else{
           throw "Invalid Operation";
       }
   }
   return ans;
   assert(input.size() == ans.size());
}


class TimeOuttedTest : public testing::Test{
protected:
    // Remember that SetUp() is run immediately before a test starts.
    // This is a good place to record the start time.
    void SetUp() override { start_time_ = time(nullptr); }

    // TearDown() is invoked immediately after a test finishes.  Here we
    // check if the test was too slow.
    void TearDown() override {
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

template<typename Cache>
class LRUCacheTest : public TimeOuttedTest{
    public:
    void givenCache(Cache& aCache){
        cache = aCache;
    }
    void givenInput(const std::vector<TestUnit>& aInput){
        input = aInput;
    }

    void expectCacheToReturn(const std::vector<std::optional<int>>& aExpected){
        expected = aExpected;
        ans = exerciseCache(cache, input);
        EXPECT_EQ(expected.size(), ans.size());
        for (int i = 0; i < ans.size(); ++i) {
            EXPECT_EQ(expected[i], ans[i]) << "Vectors x and y differ at index " << i;
        }	
    }
    private:
    Cache cache;
    std::vector<TestUnit> input;
    std::vector<std::optional<int>> expected,ans;

};

using LRUCacheTestSolution1 = LRUCacheTest<LRUCache_solution1>;

TEST_F(LRUCacheTestSolution1, Solution1_basicTest1){
    constexpr size_t kCapacity = 2;
	LRUCache_solution1 cache1(kCapacity);
    givenCache(cache1);
    givenInput(std::vector<TestUnit>{{Insert,"1 50"},{Get,"1"}});
    expectCacheToReturn(std::vector<std::optional<int>>{{},{50}});
}

TEST_F(LRUCacheTestSolution1, Solution1_basicTest_not_preset){
    constexpr size_t kCapacity = 2;
	LRUCache_solution1 cache1(kCapacity);
    givenCache(cache1);
    givenInput(std::vector<TestUnit>{{Insert,"1 50"},{Get,"2"}});
    expectCacheToReturn(std::vector<std::optional<int>>{{},{}});
}

TEST_F(LRUCacheTestSolution1, Solution1_basic_overflow_capacity){
    constexpr size_t kCapacity = 2;
	LRUCache_solution1 cache1(kCapacity);
    givenCache(cache1);
    givenInput(std::vector<TestUnit>{{Insert,"1 1"},{Insert,"2 2"},{Get,"1"},{Get,"2"},{Insert,"3 3"},{Get,"1"},{Get,"2"},{Get,"3"}});
    expectCacheToReturn(std::vector<std::optional<int>>{
            {},
            {},
            {1},
            {2},
            {},
            {},//1 is eviced by insert 3,3
            {2},
            {3}
        });
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

