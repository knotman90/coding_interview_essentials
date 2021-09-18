
using DPTable = std::vector<std::vector<int>>;

int min_difficulty_scheduler_DP_bottomup(const std::vector<int>& I, int d)
{
  const int num_tasks = I.size();
  const int INF       = std::numeric_limits<int>::max();

  if (num_tasks < d)
    return -1;

  DPTable T(d, std::vector<int>(num_tasks, INF));

  // initializing values for the first day
  int maxV = std::numeric_limits<int>::min();
  for (int j = 0; j < num_tasks; j++)
  {
    maxV    = std::max(maxV, I[j]);
    T[0][j] = maxV;
  }

  for (int i = 1; i < d; i++)
  {
    for (int j = 0; j < num_tasks; j++)
    {
      // l is the number of tasks scheduled the previous days i-1 days
      // l must be at least i-1 (it is impossible to schedule them otherwise)
      for (int l = i - 1; l < j; l++)
      {
        // elements from [0,l] the scheduled the days before and [l+1,j] today
        const auto start_task_dth_day = std::begin(I) + l + 1;
        const auto end_task_dth_day   = std::begin(I) + j + 1;
        auto max_tasks_second_day =
            *std::max_element(start_task_dth_day, end_task_dth_day);

        T[i][j] = std::min(T[i][j], T[i - 1][l] + max_tasks_second_day);
      }
    }
  }

  return T[d - 1][num_tasks - 1];
}
