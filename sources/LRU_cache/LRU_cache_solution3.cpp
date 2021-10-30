class LRUCache_solution1 {
 using Key = int;
    using Value = int;
    
    using ValueMap = std::unordered_map<Key, Value>;
    using PositionList = std::list<Key>;
    using PositionListIterator = PositionList::const_iterator;   
    using PositionMap = std::unordered_map<Key,PositionListIterator>;
        
    ValueMap VP;
    PositionMap PM;
    PositionList PL;
    public:
    LRUCache_solution1() = default;
    LRUCache_solution1(const size_t aCapacity) : mCapacity(aCapacity){}
    
    std::optional<Value> get(const Key& key) {
        if(auto it = VP.find(key); it != VP.end()){
            moveFront(key);
            return VP[key];
        }
        return {};
    }
    
    void put(const Key& key, const Value& value)
    {
        if(auto it = VP.find(key); it != VP.end()){
            updateValue(key, value);
            return;
        }
        
        if(VP.size() >= mCapacity){
            eraseLeastRecentlyUsed();
            put(key, value);
        }else{
            VP.insert({key, value});
            PL.push_front(key);
            PM.insert({key,PL.begin()});
        }
    }

    void setCapacity(const size_t aCapacity){
        mCapacity = aCapacity;
    }
    private:
    size_t mCapacity;
    
    void moveFront(const Key& key){
        auto list_it = PM[key];
        PL.erase(list_it);
        PL.push_front(key);
        PM[key]=PL.begin();      
    }
    
    void updateValue(const Key& key, const Value& value)
    {
        VP[key] = value;
        moveFront(key);
    }
    
    void eraseLeastRecentlyUsed(){
        auto key = PL.back();
        PM.erase(key);
        PL.pop_back();
        VP.erase(key);
    } 
};



