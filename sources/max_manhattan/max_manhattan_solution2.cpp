using Matrix = std::vector<std::vector<int>>;
using Cell   = std::pair<int, int>;

template <typename SeedType, typename T, typename... Rest>
void hash_combine(SeedType& seed, const T& v, const Rest&... rest)
{
    seed ^= std::hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    (hash_combine(seed, rest), ...);
}
struct TupleHash
    : public std::unary_function<std::tuple<int, int, int>, std::size_t>
{
  std::size_t operator()(const std::tuple<int, int, int>& k) const
  {
    size_t seed = 0;
    hash_combine(seed,std::get<0>(k),std::get<1>(k),std::get<2>(k));
    return seed;
  }
};

using Cache = std::unordered_map<std::tuple<int, int, int>, int, TupleHash>;

int max_manhattan_matrix_k_DP_topdown_helper(const Matrix& I,
                                             const unsigned K,
                                             const Cell& cell,
                                             Cache& cache)
{
  const auto [i, j] = cell;
  if (i < 0 || j < 0 || i >= I.size() || j >= I.back().size())
    return std::numeric_limits<int>::min();

  if (K == 0)
    return I[i][j];

  const auto key = std::make_tuple(K, i, j);
  if (const auto& it = cache.find(key); it != cache.end())
    return it->second;

  const auto ans = std::max(
      {I[i][j],
       max_manhattan_matrix_k_DP_topdown_helper(I, K - 1, {i - 1, j}, cache),
       max_manhattan_matrix_k_DP_topdown_helper(I, K - 1, {i + 1, j}, cache),
       max_manhattan_matrix_k_DP_topdown_helper(I, K - 1, {i, j + 1}, cache),
       max_manhattan_matrix_k_DP_topdown_helper(I, K - 1, {i, j - 1}, cache)});

  cache[key] = ans;
  return ans;
}

Matrix max_manhattan_matrix_k_DP_topdown(const Matrix& I, const unsigned K)
{
  const int rows = I.size();
  const int cols = I.back().size();
  Cache cache;

  Matrix M(I);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      M[i][j] = max_manhattan_matrix_k_DP_topdown_helper(I, K, {i, j}, cache);

  return M;
}
