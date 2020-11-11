template <typename T>
void find_path_helper(Node<T>* root, const T& target, std::vector<Node<T>*>& path)
{
    
    assert(root);//because target in guaranteed to be in the tree.
    
    //visited a new node. remember it
    path.push_back(root);
    if(root->val == target){
     //found the target element. we can stop as the path is complete
        return; 
    }
    
    //classic BST search
    if(target <= root->val)
        find_path_helper(root->left, target, path);
    else
        find_path_helper(root->right, target, path);
}

template <typename T>
std::vector<Node<T>*> find_path(Node<T>* root, const T& node)
{
    std::vector<Node<T>*> path = {};
    find_path_helper(root, node, path);
    return path;
}

template <typename T>
Node<T>* findLeastCommonAncestor_paths(Node<T>* root, const T& p, const T& q)
{
    std::vector<Node<T>*> P_p = find_path(root, p);
    std::vector<Node<T>*> P_q = find_path(root, q);
    
    //find the point up to which P_q and P_q are the same
    auto itp = begin(P_p);
    auto itq = begin(P_q);
    Node<T>* ans = *itp;
    while( (itp != end(P_p) && itq != end(P_q)) && (*itp == *itq ))
    {
        ans = *itp;
        itp++;
        itq++;
    }
    return ans;

}