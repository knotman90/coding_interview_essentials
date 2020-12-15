using Cache = std::vector<std::vector<unsigned long>>;

int num_rolls_to_target_bottom_up(const int d, const int f, const int target)
{
  Cache DP(d + 1, std::vector<unsigned long>(target + 1, 0));

  for (int j = 1; j <= f && j <= target; j++)
  {
    // only one way to make a given value with 1 dice
    DP[1][j] = 1;
  }

  // 1 way to make 0 with 0 dice
  DP[0][0] = 1;

  // num dices
  for (int i = 2; i <= d; i++)
  {
    // target value
    for (int t = 1; t <= target; t++)
    {
      // face value for the ith die
      for (int j = 1; j <= f && j <= t; j++)
      {
        DP[i][t] += DP[i - 1][t - j];
      }
    }
  }
  return DP[d][target];
}
