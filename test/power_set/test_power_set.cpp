#include <gtest/gtest.h>
#include <bits/stdc++.h>

#include "power_set_backtracking.cpp"
#include "power_set_incremental.cpp"
#include "power_set_incremental_improved.cpp"
#include "power_set_bit_manipulation.cpp"


using std::string;

class PowerSet_Fixture : public ::testing::Test{
	protected:
	
	std::vector<int> A;
	size_t expected_size = 0;
	std::vector<std::vector<int>> expected_content;

	void given_the_input_vector(const std::vector<int>& x){
		A = x;
	}


	void expect_the_size_to_be_correct(){
		expected_size = std::pow(2,A.size());
	}

	void expect_the_content_to_be(const std::vector<std::vector<int>>& exp){
		expected_content = exp;
		sort_power_set(expected_content);
	}

	void when_power_set_backtracking_is_called()
	{
		auto res = power_set_backtracking(A);
		sort_power_set(res);

		EXPECT_EQ(expected_size, res.size());
		EXPECT_EQ(expected_content, res);
	}

	void when_power_set_incremental_is_called()
	{
		auto res = power_set_incremental(A);
		sort_power_set(res);

		EXPECT_EQ(expected_size, res.size());
		EXPECT_EQ(expected_content, res);
	}

	void when_power_set_incremental_improved_is_called()
	{
		auto res = power_set_incremental_improved(A);
		sort_power_set(res);

		EXPECT_EQ(expected_size, res.size());
		EXPECT_EQ(expected_content, res);
	}

	void when_power_set_manipulation_is_called()
	{
		auto res = power_set_bit_manipulation(A);
		sort_power_set(res);

		EXPECT_EQ(expected_size, res.size());
		EXPECT_EQ(expected_content, res);
	}



private:
	void sort_power_set(std::vector<std::vector<int>>& PS){
		for(auto& x : PS)
			sort(begin(x), end(x));
		
		std::sort(begin(PS), end(PS), [](const auto& set1, const auto& set2)
		{
			if(set1.size() < set2.size())
				return true;
			if(set1.size() > set2.size())
				return false;
			
			for(int i = 0 ; i < set1.size() ; i++)
			{
				if(set1[i] < set2[i])
					return true;
				if(set1[i] > set2[i])
					return false;
			}
			
			return true;


			 });
	}

};

TEST_F(PowerSet_Fixture, given_empty_array_should_return_empty_only)
{
	std::vector<int> empty_array;
	std::vector<std::vector<int>> expected_power_set = {{}};

	given_the_input_vector(empty_array);
	expect_the_size_to_be_correct();
	expect_the_content_to_be(expected_power_set);

	when_power_set_backtracking_is_called();
	when_power_set_incremental_is_called();
	when_power_set_manipulation_is_called();
	when_power_set_incremental_improved_is_called();
}

TEST_F(PowerSet_Fixture, one_element_array)
{
	std::vector<int> one_el_array = {1};
	std::vector<std::vector<int>> expected_power_set = {{},{1}};

	given_the_input_vector(one_el_array);
	expect_the_size_to_be_correct();
	expect_the_content_to_be(expected_power_set);

	when_power_set_backtracking_is_called();
	when_power_set_incremental_is_called();
	when_power_set_manipulation_is_called();
	when_power_set_incremental_improved_is_called();
}

TEST_F(PowerSet_Fixture,vtwo_distinct_elements_array)
{
	std::vector<int> two_distinct_elements_array = {1,2};
	std::vector<std::vector<int>> expected_power_set = {{},{1},{2},{1,2}};

	given_the_input_vector(two_distinct_elements_array);
	expect_the_size_to_be_correct();
	expect_the_content_to_be(expected_power_set);

	when_power_set_backtracking_is_called();
	when_power_set_incremental_is_called();
	when_power_set_manipulation_is_called();
	when_power_set_incremental_improved_is_called();
}

TEST_F(PowerSet_Fixture, two_same_elements_array)
{
	std::vector<int> two_same_elements_array = {1,1};
	std::vector<std::vector<int>> expected_power_set = {{},{1},{1},{1,1}};

	given_the_input_vector(two_same_elements_array);
	expect_the_size_to_be_correct();
	expect_the_content_to_be(expected_power_set);

	when_power_set_backtracking_is_called();
	when_power_set_incremental_is_called();
	when_power_set_manipulation_is_called();
	when_power_set_incremental_improved_is_called();
}


TEST_F(PowerSet_Fixture, array_1_2_3_4)
{
	std::vector<int> two_same_elements_array = {1,2,3,4};
	std::vector<std::vector<int>> expected_power_set = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}, {4}, {1, 4}, {2, 4}, {1, 2, 4}, {3, 4}, {1, 3, 4}, {2, 3, 4}, {1, 2, 3, 4}};

	given_the_input_vector(two_same_elements_array);
	expect_the_size_to_be_correct();
	expect_the_content_to_be(expected_power_set);

	when_power_set_backtracking_is_called();
	when_power_set_incremental_is_called();
	when_power_set_manipulation_is_called();
	when_power_set_incremental_improved_is_called();
}

TEST_F(PowerSet_Fixture, array_4_3_2_1)
{
	std::vector<int> two_same_elements_array = {4,3,2,1};
	std::vector<std::vector<int>> expected_power_set = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}, {4}, {1, 4}, {2, 4}, {1, 2, 4}, {3, 4}, {1, 3, 4}, {2, 3, 4}, {1, 2, 3, 4}};

	given_the_input_vector(two_same_elements_array);
	expect_the_size_to_be_correct();
	expect_the_content_to_be(expected_power_set);

	when_power_set_backtracking_is_called();
	when_power_set_incremental_is_called();
	when_power_set_manipulation_is_called();
	when_power_set_incremental_improved_is_called();
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}