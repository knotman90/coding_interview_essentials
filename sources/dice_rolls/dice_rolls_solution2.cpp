using Cache = std::vector<std::vector<unsigned long>>;

int num_rolls_to_target_memoization_helper(const int target,
                                           const int dices,
                                           const int f,
                                           Cache& cache)
{
  constexpr unsigned long MOD = 1e9 + 7;

  if (target < 0 || dices < 0)
    return 0;

  if (dices == 0)
    return target == 0;

  if (cache[dices][target] != -1)
    return cache[dices][target];

  unsigned long ans = 0;
  for (int i = 1; i <= f; i++, ans %= MOD)
    ans +=
        num_rolls_to_target_memoization_helper(target - i, dices - 1, f, cache);

  cache[dices][target] = ans;
  return ans;
}

int num_rolls_to_target_memoization(int d, int f, int target)
{
  Cache DP(d + 1, std::vector<unsigned long>(target + 1, -1));
  return num_rolls_to_target_memoization_helper(target, d, f, DP);
}
