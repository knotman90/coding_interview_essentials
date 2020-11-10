#include "binary_tree.h"


template<typename T>
Node<T>* copy_binary_tree(const Node<T>*const root)
{
    if(!root)
        return nullptr;
    
    auto root_copy = new Node<T>(root->payload);
    root_copy->left = copy_binary_tree(root->left);
    root_copy->right = copy_binary_tree(root->right);
    return root_copy;
}



template<typename T>
void mirror_binary_tree_in_place(Node<T>*const node)
{
    using std::swap;

    if(!node)
        return;
    
    mirror_binary_tree_in_place(node->left);
    mirror_binary_tree_in_place(node->right);
    swap(node->left, node->right);
}

template<typename T>
Node<T>* mirror_binary_tree(const Node<T>*const root){
    auto&& tree_copy = copy_binary_tree(root);
    mirror_binary_tree_in_place(tree_copy);
    return tree_copy;
}