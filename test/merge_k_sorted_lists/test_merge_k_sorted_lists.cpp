#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "list.h"
using Book::List::Node;
#include "test_utils.h"

#include "merge_k_sorted_lists_solution1.cpp"
#include "merge_k_sorted_lists_solution2.cpp"


template<typename T = int>
using List = Node<T>*;

template<typename T = int>
using Lists = std::vector<List<T>>;



TEST(merge_k_sorted_lists, example1)
{
    {
        Lists<int> input;
        input.push_back(Book::List::from_vector(std::vector<int>{1,4,5}));
        input.push_back(Book::List::from_vector(std::vector<int>{1,3,4}));
        input.push_back(Book::List::from_vector(std::vector<int>{2,6}));

        List<int> expected = Book::List::from_vector(std::vector<int>{1,1,2,3,4,4,5,6});
        
        const Node<int> *ans = merge_k_sorted_list_brute_force(input);
	    EXPECT_TRUE(Book::List::equal(expected, ans)) <<
             std::endl<< "exp = " << to_string(Book::List::to_vector(expected))<< std::endl<<
             "ans = " << to_string(Book::List::to_vector(ans)) ;
    }
}

TEST(merge_k_sorted_lists, example2)
{
    {
        Lists<int> input;
        input.push_back(Book::List::from_vector(std::vector<int>{1,2,3}));
        input.push_back(Book::List::from_vector(std::vector<int>{4,5,6}));
        input.push_back(Book::List::from_vector(std::vector<int>{7,8,9}));

        List<int> expected = Book::List::from_vector(std::vector<int>{1,2,3,4,5,6,7,8,9});
        
        const Node<int> *ans = merge_k_sorted_list_brute_force(input);
	    EXPECT_TRUE(Book::List::equal(expected, ans)) <<
             std::endl<< "exp = " << to_string(Book::List::to_vector(expected))<< std::endl<<
             "ans = " << to_string(Book::List::to_vector(ans)) ;
    }
}


TEST(merge_k_sorted_lists, singlelist)
{
    {
        Lists<int> input;
        input.push_back(Book::List::from_vector(std::vector<int>{1,2,3,4}));
        
        List<int> expected = Book::List::from_vector(std::vector<int>{1,2,3,4});
        
        const Node<int> *ans = merge_k_sorted_list_brute_force(input);
	    EXPECT_TRUE(Book::List::equal(expected, ans)) <<
             std::endl<< "exp = " << to_string(Book::List::to_vector(expected))<< std::endl<<
             "ans = " << to_string(Book::List::to_vector(ans)) ;
    }
}

TEST(merge_k_sorted_lists, allEqualSizeAndValue)
{
    {
        Lists<int> input;
        input.push_back(Book::List::from_vector(std::vector<int>{1,2,3,}));
        input.push_back(Book::List::from_vector(std::vector<int>{1,2,3}));
        input.push_back(Book::List::from_vector(std::vector<int>{1,2,3}));
        input.push_back(Book::List::from_vector(std::vector<int>{1,2,3}));
        input.push_back(Book::List::from_vector(std::vector<int>{1,2,3}));
        input.push_back(Book::List::from_vector(std::vector<int>{1,2,3}));
        input.push_back(Book::List::from_vector(std::vector<int>{1,2,3}));
        
        List<int> expected = Book::List::from_vector(std::vector<int>{1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3});

        const Node<int> *ans = merge_k_sorted_list_brute_force(input);
	    EXPECT_TRUE(Book::List::equal(expected, ans)) <<
             std::endl<< "exp = " << to_string(Book::List::to_vector(expected))<< std::endl<<
             "ans = " << to_string(Book::List::to_vector(ans)) ;
    }
}

TEST(merge_k_sorted_lists, altenating)
{
    {
        Lists<int> input;
        input.push_back(Book::List::from_vector(std::vector<int>{1,3,5,7,9}));
        input.push_back(Book::List::from_vector(std::vector<int>{0,0,2,4,6,8,10}));
        input.push_back(Book::List::from_vector(std::vector<int>{-1,-1,-1}));
        
        List<int> expected = Book::List::from_vector(std::vector<int>{-1,-1,-1,0,0,1,2,3,4,5,6,7,8,9,10});

        const Node<int> *ans = merge_k_sorted_list_brute_force(input);
	    EXPECT_TRUE(Book::List::equal(expected, ans)) <<
             std::endl<< "exp = " << to_string(Book::List::to_vector(expected))<< std::endl<<
             "ans = " << to_string(Book::List::to_vector(ans)) ;
    }
}



TEST(merge_k_sorted_lists, random1)
{
    {
        Lists<int> input;
        input.push_back(Book::List::from_vector(std::vector<int>{9,19,24,36,37,39,41,45,47,70,75,78,95,95,104,110,117,132,142,149,173,177,179,217,224,238,247,276,325,345,347,353,356,362,365,377,378,397,402,420,421,449,454,477,489,492,499,500,511,511,514,528,535,538,542,548,549,555,565,570,572,588,596,598,605,611,613,638,659,664,665,670,677,680,698,720,734,744,746,747,779,781,807,818,823,828,847,850,866,888,891,901,929,929,935,946,979,990,994,998}));
        input.push_back(Book::List::from_vector(std::vector<int>{14,23,33,39,55,57,71,74,80,80,80,90,104,115,152,155,156,157,158,177,193,202,210,213,224,256,279,286,296,307,309,314,317,327,346,371,379,411,420,439,448,453,461,473,491,509,524,528,531,539,552,557,559,578,581,601,602,626,631,632,632,658,659,663,672,681,708,711,720,728,742,746,757,773,777,785,790,790,792,802,807,810,812,814,828,833,851,854,868,880,903,907,922,937,945,952,956,976,977,995}));
        input.push_back(Book::List::from_vector(std::vector<int>{5,8,9,20,36,67,68,84,85,90,97,100,118,119,132,137,150,187,187,196,207,208,224,240,251,254,280,288,292,295,295,301,307,311,318,320,323,326,341,374,375,375,382,384,385,387,396,404,404,417,417,421,447,464,468,497,497,504,553,556,565,567,568,617,624,628,640,643,649,659,661,663,678,711,719,724,734,748,764,765,770,776,781,806,812,813,814,826,841,846,894,894,918,922,935,938,943,966,973,984}));
        
        List<int> expected = Book::List::from_vector(std::vector<int>{5,8,9,9,14,19,20,23,24,33,36,36,37,39,39,41,45,47,55,57,67,68,70,71,74,75,78,80,80,80,84,85,90,90,95,95,97,100,104,104,110,115,117,118,119,132,132,137,142,149,150,152,155,156,157,158,173,177,177,179,187,187,193,196,202,207,208,210,213,217,224,224,224,238,240,247,251,254,256,276,279,280,286,288,292,295,295,296,301,307,307,309,311,314,317,318,320,323,325,326,327,341,345,346,347,353,356,362,365,371,374,375,375,377,378,379,382,384,385,387,396,397,402,404,404,411,417,417,420,420,421,421,439,447,448,449,453,454,461,464,468,473,477,489,491,492,497,497,499,500,504,509,511,511,514,524,528,528,531,535,538,539,542,548,549,552,553,555,556,557,559,565,565,567,568,570,572,578,581,588,596,598,601,602,605,611,613,617,624,626,628,631,632,632,638,640,643,649,658,659,659,659,661,663,663,664,665,670,672,677,678,680,681,698,708,711,711,719,720,720,724,728,734,734,742,744,746,746,747,748,757,764,765,770,773,776,777,779,781,781,785,790,790,792,802,806,807,807,810,812,812,813,814,814,818,823,826,828,828,833,841,846,847,850,851,854,866,868,880,888,891,894,894,901,903,907,918,922,922,929,929,935,935,937,938,943,945,946,952,956,966,973,976,977,979,984,990,994,995,998});

        const Node<int> *ans = merge_k_sorted_list_brute_force(input);
	    EXPECT_TRUE(Book::List::equal(expected, ans)) <<
             std::endl<< "exp = " << to_string(Book::List::to_vector(expected))<< std::endl<<
             "ans = " << to_string(Book::List::to_vector(ans)) ;
    }
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

