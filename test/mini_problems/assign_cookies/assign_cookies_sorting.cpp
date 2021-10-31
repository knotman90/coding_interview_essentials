    int max_content_children(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        auto it_g = g.begin();
        auto it_s = s.begin();
        size_t ans = 0;
        while(it_g != g.end() && it_s != s.end()){
            if(*it_s >= *it_g){
                std::advance(it_g, 1);
                ans++;
            }
            std::advance(it_s, 1);
        }
        return ans;       
    }