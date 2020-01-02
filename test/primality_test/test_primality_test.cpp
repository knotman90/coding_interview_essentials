#include <gtest/gtest.h>
#include <bits/stdc++.h>

#include "primality_test_solution1.cpp"
#include "primality_test_solution2.cpp"
#include "primality_test_solution3.cpp"

using std::string;

TEST(primality_test, two_three_prime_test)
{
    EXPECT_FALSE(is_prime_brute_force(2));
	EXPECT_FALSE(is_prime_simple(2));
    EXPECT_FALSE(is_prime_final(2));

	EXPECT_TRUE(is_prime_brute_force(3));
	EXPECT_TRUE(is_prime_simple(3));
    EXPECT_TRUE(is_prime_final(3));
}

TEST(primality_test, twenty_eight_nine_prime_test)
{
    EXPECT_FALSE(is_prime_brute_force(28));
	EXPECT_FALSE(is_prime_simple(28));
    EXPECT_FALSE(is_prime_final(28));

	EXPECT_TRUE(is_prime_brute_force(29));
	EXPECT_TRUE(is_prime_simple(29));
    EXPECT_TRUE(is_prime_final(29));
}


TEST(primality_test, max_int_prime_test)
{
    EXPECT_TRUE(is_prime_brute_force(2147483647));
	EXPECT_TRUE(is_prime_simple(2147483647));
    EXPECT_TRUE(is_prime_final(2147483647));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

