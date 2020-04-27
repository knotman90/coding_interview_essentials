int num_rolls_to_target_bruteforce(const int dices,
                                   const int f,
                                   const int target)
{
  constexpr unsigned long MOD = 1e9 + 7;
  if (target < 0 || dices < 0)
    return 0;

  if (dices == 0)
    return target == 0 ? 1 : 0;
    
  cout << "Solving for: \tdices = "<<  dices << ",\ttarget = " << target <<endl;
  // for each possible value this dice can assume
  int ans = 0;
  for (int i = 1; i <= f; i++, ans %= MOD)
  {
    
    ans += num_rolls_to_target_bruteforce(dices - 1, f, target - i);
  }
  return ans;
}
