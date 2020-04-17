#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

#include "valid_parenthesis_solution1.cpp"
#include "valid_parenthesis_solution2.cpp"

#include "algorithm.h"

TEST(valid_parenthesis, test_empty)
{
  const std::string s = "";

  EXPECT_TRUE(validate_parenthesized_string_bruteforce(s));
}

TEST(valid_parenthesis, test_all_asteriscs)
{
  const std::string s = "********************";

  EXPECT_TRUE(validate_parenthesized_string_bruteforce(s));
}


TEST(valid_parenthesis, test_all_valid_no_asteriscs)
{
  const std::string s = "";
  constexpr size_t num_pairs = 5;

  const auto all_valid = Book::Algorithm::generate_well_parenthesized_combinations(num_pairs);
  for(const auto& s: all_valid){
  	cout<<"Validating:"<<s<<endl;
  	EXPECT_TRUE(validate_parenthesized_string_bruteforce(s));
  }
}

TEST(valid_parenthesis, test_all_valid_substitute_chars_with_asteriscs)
{
  const std::string s = "";
  constexpr size_t num_pairs = 1;

  const auto all_valid = Book::Algorithm::generate_well_parenthesized_combinations(num_pairs);
  
  for(auto s: all_valid){
  	
  	const int num_substitutions = Book::Algorithm::get_random_in_range<int>(0,s.size()-1);
  	for(int i = 0 ; i < num_substitutions ; i++)
  	{
  		const auto idx = Book::Algorithm::get_random_in_range<int>(0,s.size()-1);
  		s[idx] = '*';
  	}

  	cout<<"Validating:"<<s<<endl;
  	EXPECT_TRUE(validate_parenthesized_string_bruteforce(s));
  }
}

TEST(valid_parenthesis, test_all_valid_append_open_make_string_invalid)
{
  const std::string s = "";
  constexpr size_t num_pairs = 5;

  const auto all_valid = Book::Algorithm::generate_well_parenthesized_combinations(num_pairs);
  
  for(auto s: all_valid){
  	const auto idx = Book::Algorithm::get_random_in_range<int>(0,s.size()-1);
  	s.insert(idx,"{");
  	cout<<"Validating:"<<s<<endl;
  	EXPECT_FALSE(validate_parenthesized_string_bruteforce(s));
  }
}

TEST(valid_parenthesis, test_all_valid_append_closed_make_string_invalid)
{
  const std::string s = "";
  constexpr size_t num_pairs = 5;

  const auto all_valid = Book::Algorithm::generate_well_parenthesized_combinations(num_pairs);
  
  for(auto s: all_valid){
  	const auto idx = Book::Algorithm::get_random_in_range<int>(0,s.size()-1);
  	s.insert(idx,"}");
  	cout<<"Validating:"<<s<<endl;
  	EXPECT_FALSE(validate_parenthesized_string_bruteforce(s));
  }
}


TEST(valid_parenthesis, test_all_valid_append_closed_make_string_invalid_but_with_asteriscs_before_becomes_valid)
{
  const std::string s = "";
  constexpr size_t num_pairs = 6;

  const auto all_valid = Book::Algorithm::generate_well_parenthesized_combinations(num_pairs);
  
  for(auto s: all_valid){
  	const auto idx = Book::Algorithm::get_random_in_range<int>(0,s.size()-1);
 	s.insert(idx,"}");
 	s.insert(idx,"*");
 	//cout<<"closed added at "<<idx<<" "<<s<<endl;
  	const int num_ast = Book::Algorithm::get_random_in_range<int>(1,s.size()-1); 
  	for(int i = 0 ; i < num_ast ; i++)
  	{
  		s.insert(idx,"*");
  	}

  	cout<<"Validating:"<<s<<endl;
  	ASSERT_TRUE(validate_parenthesized_string_bruteforce(s));
  }
}





int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
