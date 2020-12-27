template <typename SeedType, typename T, typename... Rest>
void hash_combine(SeedType& seed, const T& v, const Rest&... rest)
{
    seed ^= std::hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    (hash_combine(seed, rest), ...);
}
struct PairHasher
    : public std::unary_function<std::pair<int, int>, std::size_t>
{
  std::size_t operator()(const std::pair<int, int>& k) const
  {
    size_t seed = 0;
    hash_combine(seed,std::get<0>(k),std::get<1>(k));
    return seed;
  }
};
