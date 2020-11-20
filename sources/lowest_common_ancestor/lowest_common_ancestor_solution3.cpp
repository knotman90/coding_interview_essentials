template <typename T>
void find_path_optimized_helper(Node<T>* root, const T& p, const T& q,  Node<T>*& last_common)
{
    assert(root);//because target in guaranteed to be in the tree.
        
    //LCA is the current node. Either p is descendant of q or the other way around
    if(root->val == p || root->val == q){
        last_common = root;
        return; 
    }
    last_common = root;
    
    //paths for p and q takes different direction from here
    if((p <= root->val && q > root->val) || (p > root->val && q <= root->val))
        return;
    
    //they are both lower or equal than val or both higher
    if(p <= root->val){
        find_path_optimized_helper(root->left, p,q , last_common);
    }
    else
        find_path_optimized_helper(root->right, p,q, last_common);
}



template <typename T>
Node<T>* findLeastCommonAncestor_paths_optimized(Node<T>* root, const T& p, const T& q)
{
    Node<T>* ans = root;
    find_path_optimized_helper(root, p, q, ans);
    return ans;

}