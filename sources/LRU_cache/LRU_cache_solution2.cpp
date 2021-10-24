class LRUCache_logn2 {
 private:
    size_t C;
    int cnt = 0;
    
    using Position = int;
    using Key = int;
    using Value = int;
    
    std::unordered_map<Key, std::pair<Value, Position>> KV;
    std::map<Position,Key> PK;
    public:
    LRUCache_logn2() = default;
    LRUCache_logn2(const size_t aCapacity) : C(aCapacity){}
    

    Value update_value(const Key key, const Value value)
    {
        assert(KV.find(key) != KV.end());
        auto kv_it = KV.find(key);
        
        const auto [k,pair] = *kv_it;
        const auto [v,p] = pair;
        
        auto pk_it = PK.find(p);
        
        KV.erase(kv_it);
        PK.erase(pk_it);
        put(key, value);
        return value;
        
    }

    std::optional<Value> get(const Key& key) {
        auto kv_it = KV.find(key); 
        if(kv_it == KV.end())
            return {};
        
        return update_value(key, kv_it->second.first);
        
    }
    
    void put(const Key& key, const Value& value)
    {
        if(KV.find(key) != KV.end())
        {
           // cout<<"key" <<key<<"already present. updating to"<<value<<endl;
            update_value(key, value);
            return;
        }
        if(KV.size() >= C)
        {
            auto last = PK.begin();
            auto [p,k] = *last;
            PK.erase(last);
            KV.erase(k);
        }
        cnt++;
        KV.insert({key,{value,cnt}});
        PK.insert({cnt,key});

    }

    void setCapacity(const size_t aCapacity){
        C = aCapacity;
    }

};



