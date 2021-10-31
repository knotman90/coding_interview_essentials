    int n_ary_treedepth_itearative(Node* root)
    {
        if(!root)
            return 0;
        
        std::stack<std::pair<Node*, int>> nodes;
        nodes.push({root,1});
        
        int ans = 1;
        while(!nodes.empty())
        {
            auto [node, level] = nodes.top();
            nodes.pop();
            ans = std::max(ans, level);
            for(const auto child : node->children)
            {
                nodes.push({child, level+1});
            }            
        }
        
        return ans;
    }