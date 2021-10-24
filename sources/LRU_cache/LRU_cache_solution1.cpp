template <typename Key, typename Value>
class LRUCache_logn
{
  using UpdateTime = int;

  // key -> value,updateTime (remember last
  // time this value was inserted/updated)
  using ValueMap = std::unordered_map<Key, std::pair<Value, UpdateTime>>;
  // order keys based on updatetime
  using TimeKeyMap = std::map<UpdateTime, Key>;

  ValueMap VP;
  TimeKeyMap TK;
  UpdateTime time = 0;

 public:
  LRUCache_logn() = default;
  LRUCache_logn(const size_t aCapacity) : mCapacity(aCapacity)
  {
  }

  std::optional<Value> get(const Key& key)
  {
    if (VP.contains(key))
    {
      ++time;
      const std::pair<Value, UpdateTime>& valTime = VP[key];
      const auto val = valTime.first;
      const auto oldTime = valTime.second;
      VP[key]                    = {val, time};
      TK.erase(oldTime);
      TK.insert({time, key});
      return val;
    }
    return {};
  }

  void put(const Key& key, const Value& value)
  {
    if (VP.contains(key))
    {
      const auto& [oldval, oldtimestamp] = VP[key];
      VP[key]                            = {value, oldtimestamp};
      get(key);  // update time
    }
    else
    {
      if (VP.size() >= mCapacity)
      {
        auto [timestamp, eraseblekey] = *TK.begin();
        VP.erase(eraseblekey);
        TK.erase(TK.begin());
        put(key, value);
      }
      else
      {
        ++time;
        VP[key]  = {value, time};
        TK[time] = key;
      }
    }
  }

  void setCapacity(const size_t aCapacity)
  {
    mCapacity = aCapacity;
  }

 private:
  size_t mCapacity;
};
