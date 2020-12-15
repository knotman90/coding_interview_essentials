int num_rolls_to_target_bruteforce(const int dices,
                                   const int f,
                                   const int target)
{
  constexpr unsigned long MOD = 1e9 + 7;
  //ops. overreached
  if (target < 0 || dices < 0)
    return 0;

  //no more die to roll. Have we reached the target value?
  if (dices == 0)
    return target == 0 ? 1 : 0;
    
  // for each possible face
  int ans = 0;
  for (int i = 1; i <= f; i++, ans %= MOD)
  {
    //we assume we rolled the face with value i and solve the associated subproblem
    ans += num_rolls_to_target_bruteforce(dices - 1, f, target - i);
  }
  return ans;
}
