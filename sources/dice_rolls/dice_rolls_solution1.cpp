int num_rolls_to_target_bruteforce_helper(const int target,
                                          const int dices,
                                          const int f)
{
  constexpr unsigned long MOD = 1e9 + 7;
  if (target < 0 || dices < 0)
    return 0;

  if (dices == 0)
    return target == 0;

  unsigned long ans = 0;
  for (int i = 1; i <= f; i++, ans %= MOD)
    ans += num_rolls_to_target_bruteforce_helper(target - i, dices - 1, f);

  return ans;
}

int num_rolls_to_target_bruteforce(int d, int f, int target)
{
  return num_rolls_to_target_bruteforce_helper(target, d, f);
}
