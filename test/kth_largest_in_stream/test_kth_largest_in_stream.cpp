#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "IKThLargestInStream.h"
#include "kth_largest_in_stream_solution1.cpp"
#include "kth_largest_in_stream_solution2.cpp"
#include "kth_largest_in_stream_solution3.cpp"


template <typename T>
class KthLargestInStreamFixture : public ::testing::Test
{
 public:
  T value_;
};

using KthLargestInStreamImplementations = ::testing::
    Types<KthLargestInStreamArray, KthLargestInStreamMap, KthLargestInStreamHeap>;

TYPED_TEST_SUITE(KthLargestInStreamFixture, KthLargestInStreamImplementations);


TYPED_TEST(KthLargestInStreamFixture, test1)
{
  TypeParam KLargestImpl = this->value_;
  std::vector<int> kInitial_input = {1,2,3,4};
  const size_t kK = kInitial_input.size();

  KLargestImpl.initialize(kInitial_input, kK);

  ASSERT_EQ(1, KLargestImpl.add(-1));
  ASSERT_EQ(1, KLargestImpl.add(-1));
  ASSERT_EQ(1, KLargestImpl.add(-1));
  ASSERT_EQ(1, KLargestImpl.add(0));
}

TYPED_TEST(KthLargestInStreamFixture, test2)
{
  TypeParam KLargestImpl = this->value_;
  std::vector<int> kInitial_input = {1,2,3,4};
  const size_t kK = kInitial_input.size();

  KLargestImpl.initialize(kInitial_input, kK);

  ASSERT_EQ(2, KLargestImpl.add(5));
  ASSERT_EQ(3, KLargestImpl.add(5));
  ASSERT_EQ(4, KLargestImpl.add(5));
  ASSERT_EQ(5, KLargestImpl.add(5));
  ASSERT_EQ(5, KLargestImpl.add(7));
}


TYPED_TEST(KthLargestInStreamFixture, test3)
{
  TypeParam KLargestImpl = this->value_;
  std::vector<int> kInitial_input = {1,2,3,4,50,100,150,200};
  const size_t kK = 4;

  KLargestImpl.initialize(kInitial_input, kK);

  ASSERT_EQ(100, KLargestImpl.add(250));  // 100,150,200,250
  ASSERT_EQ(100, KLargestImpl.add(50));  // 100,150,200,250
  ASSERT_EQ(110, KLargestImpl.add(110)); // 110,150,200,250
  ASSERT_EQ(150, KLargestImpl.add(180)); //150,180,200,250
  ASSERT_EQ(180, KLargestImpl.add(500)); // 180,200,250,500
  ASSERT_EQ(180, KLargestImpl.add(-500));// 180,200,250,500
}


TYPED_TEST(KthLargestInStreamFixture, test_alway_iknsert_largerkis1)
{
  TypeParam KLargestImpl = this->value_;
  std::vector<int> kInitial_input = {1,2,3,4,50,100,150,200};
  const size_t kK = 1;

  KLargestImpl.initialize(kInitial_input, kK);

  for(int i = 201; i < 100 ; i++){
    ASSERT_EQ(i, KLargestImpl.add(i));
  }
}

TYPED_TEST(KthLargestInStreamFixture, test4)
{
  TypeParam KLargestImpl = this->value_;
  std::vector<int> kInitial_input = {200,150,100,50,4,3,2,1};
  const size_t kK = 1;

  KLargestImpl.initialize(kInitial_input, kK);

  for(int i = 201; i < 100 ; i++){
    ASSERT_EQ(i, KLargestImpl.add(i));
  }
}


TYPED_TEST(KthLargestInStreamFixture, test5)
{
  TypeParam KLargestImpl = this->value_;
  std::vector<int> kInitial_input = {10,20,11};
  const size_t kK = 3;

  KLargestImpl.initialize(kInitial_input, kK);

  ASSERT_EQ(11, KLargestImpl.add(70));
  ASSERT_EQ(20, KLargestImpl.add(50));
  ASSERT_EQ(40, KLargestImpl.add(40));
  ASSERT_EQ(50, KLargestImpl.add(100));
  ASSERT_EQ(50, KLargestImpl.add(5));

  
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

