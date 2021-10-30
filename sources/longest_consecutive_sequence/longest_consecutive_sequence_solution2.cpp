using pii = std::pair<std::optional<int>,std::optional<int>>; 
using Graph = std::unordered_map<int, pii>;

Graph build_graph(std::vector<int>& L)
{
    Graph ans;
    for(const auto& curr : L){
        if(ans.contains(curr)){
            continue;
        }
        ans.insert({curr, {}});
        
        auto prev = curr-1;
        if(ans.contains(prev)){
            assert(!ans[prev].second);
            ans[prev].second = curr;
            ans[curr].first = prev;
        }
        
        auto next = curr+1;
        if(ans.contains(next)){
            assert(!ans[next].first);
            ans[next].first = curr;
            ans[curr].second = next;
        }
    }
    return ans;
}

template<bool Direction>
size_t find_longest_connected_component(Graph& g, const int start_node)
{
    size_t ans = 0;
    auto curr_node = start_node;
    while(g.contains(curr_node))
    {
        std::optional<int> connected_node = std::nullopt;
        if constexpr (Direction){
            connected_node = g[curr_node].second;
        }else{
            connected_node = g[curr_node].first;
        }
        g.erase(curr_node);
        if(!connected_node.has_value())
            break;
        ans++;
        curr_node = *connected_node;
    }
    return ans;
}

size_t find_longest_connected_component(std::vector<int>& L,Graph& g)
{
    constexpr auto Left = false;
    constexpr auto Right = true;
    size_t ans = 0;
    for(const auto& l : L){
        if(!g.contains(l)){
            continue; //already visited
        }
        const auto length_left_from_l = find_longest_connected_component<Left>(g,l); 
        //l is erased now: visit right from the next if exists and add 1 to account for the first hop done here
        const auto length_right_from_l = g.contains(l+1) ? find_longest_connected_component<Right>(g,l+1)+1: 0;
        ans = std::max(ans, length_left_from_l+length_right_from_l+1);
    }
    return ans;
}

size_t longest_consecutive_sequence_lineartime(std::vector<int>& L){
    if(const auto size = L.size(); size <= 1)
        return size;
    
    auto graph = build_graph(L);
    return find_longest_connected_component(L,graph);
}