template<typename T>
Node<T>* mirror_binary_tree_on_the_fly(Node<T>*const node)
{
    if(!node)
        return nullptr;
    
    auto root_mirror = new Node<T>(node->payload);
    root_mirror->right  = mirror_binary_tree_on_the_fly(node->left);
    root_mirror->left  = mirror_binary_tree_on_the_fly(node->right);
    return root_mirror;
}
