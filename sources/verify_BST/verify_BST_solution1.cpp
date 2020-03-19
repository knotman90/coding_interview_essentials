static constexpr long INF = std::numeric_limits<long>::max();
    
inline bool isValidBST_helper(const TreeNode*const  root, const long lower, const long upper )
{
    if(!root)
        return true;
    
    return (root->val > lower) && (root->val < upper) &&
        isValidBST_helper(root->left, lower, root->val) && 
        isValidBST_helper(root->right, root->val, upper);
}

bool isValidBST(TreeNode* root)
{
    return isValidBST_helper(root, -INF, INF); 
}