#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "binary_tree.h"
#include "mirror_binary_tree_solution1.cpp"
#include "mirror_binary_tree_solution2.cpp"


template<typename T>
Node<T>* treeFromList_helper( const std::vector<T>& payloads, const int pos)
{
    if(pos >= payloads.size())
        return nullptr;
    Node<T>* root = new Node<T>(payloads[pos]);
    root->left = treeFromList_helper<T>(payloads, pos*2);
    root->right = treeFromList_helper<T>(payloads, pos*2+1);
    return root;
}

template<typename T>
Node<T>* treeFromList( std::vector<T>& payloads){
    payloads.insert(begin(payloads), T{});
    return treeFromList_helper(payloads, 1);
}

template<typename T>
bool equals(Node<T>* t1, Node<T>* t2)
{
    if(!t1 && !t2)
        return true;
    if((!t1 && t2) || (t1 && !t2))  
        return false;
    
    return (t1->payload==t2->payload) && equals(t1->left, t2->left)
    && equals(t1->right, t2->right);


}

TEST(mirror_binary_tree, test_empty)
{
     std::vector<int> values = {};
     std::vector<int> values_mirror = {};

    auto tree = treeFromList<int>(values);
    auto tree_mirror = treeFromList<int>(values_mirror);
    
    auto res = mirror_binary_tree(tree);
	EXPECT_TRUE(equals(tree_mirror,res ));
}


TEST(mirror_binary_tree, test_leaf)
{
     std::vector<int> values = {1};
     std::vector<int> values_mirror = {1};

    auto tree = treeFromList<int>(values);
    auto tree_mirror = treeFromList<int>(values_mirror);
    
    auto res = mirror_binary_tree(tree);
	EXPECT_TRUE(equals(tree_mirror,res ));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

