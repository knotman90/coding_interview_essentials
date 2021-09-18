#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "gas_station_solution1.cpp"
#include "gas_station_solution2.cpp"




TEST(gas_station, test_example1)
{
	std::vector<int> G = {1,2};
    std::vector<int> C = {2,1};
	
    EXPECT_EQ(1, solve_gast_station_bruteforce(G,C));
}


TEST(gas_station, test_example2)
{
	std::vector<int> G = {7,1,0,11,4};
    std::vector<int> C = {5,9,1,2,5};
	
    EXPECT_EQ(3, solve_gast_station_bruteforce(G,C));
    EXPECT_EQ(3, solve_gast_station_lineartime(G,C));
}

TEST(gas_station, test_example2_last_element_good)
{
	std::vector<int> G = {0,0,0,0,50};
    std::vector<int> C = {10,10,10,10,10};
	
    EXPECT_EQ(4, solve_gast_station_bruteforce(G,C));
    EXPECT_EQ(4, solve_gast_station_lineartime(G,C));
}

TEST(gas_station, test_example_single)
{
	std::vector<int> G = {0};
    std::vector<int> C = {100};
	
    EXPECT_EQ(0, solve_gast_station_bruteforce(G,C));
    EXPECT_EQ(0, solve_gast_station_lineartime(G,C));
}

TEST(gas_station, test_example_empty)
{
	std::vector<int> G = {};
    std::vector<int> C = {};
	
    EXPECT_EQ(-1, solve_gast_station_bruteforce(G,C));
    EXPECT_EQ(-1, solve_gast_station_lineartime(G,C));
}

TEST(gas_station, test1)
{
	std::vector<int> G = {2,3,4};
    std::vector<int> C = {3,4,3};
	
    EXPECT_EQ(-1, solve_gast_station_bruteforce(G,C));
    EXPECT_EQ(-1, solve_gast_station_lineartime(G,C));
}

TEST(gas_station, test2)
{
	std::vector<int> G = {1,2,3,4,5};
    std::vector<int> C = {3,4,5,1,2};
	
    EXPECT_EQ(3, solve_gast_station_bruteforce(G,C));
    EXPECT_EQ(3, solve_gast_station_lineartime(G,C));
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

