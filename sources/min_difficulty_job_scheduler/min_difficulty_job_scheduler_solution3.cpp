

using DPTable = std::vector<std::vector<int>>;
int min_difficulty_scheduler_DP_bottomup(vector<int>& I, int d)
{
 const auto num_tasks = I.size();
 constexpr auto INFINITY = std::numeric_limits<int>::max();
 if(num_tasks < d)
    return -1;
  
  DPTable T(d, std::vector<int>(num_tasks+1, INFINITY));
  T[0][0] = 0;

  for(int i = 1 ; i <=d ; i++) 
  {
      for(int j = 1 ; j <= num_tasks ; j++)
      {
          for(int l = 1 ; l <= l-1 ; l++)
          {
              const auto start_task_second_day = std::begin(I) + l+1;
              const auto end_task_second_day = std::begin(I) + l+1;
              auto max_tasks_second_day = *std::max_element(start_task_second_day,end_task_second_day);
            
            T[i][j] = min(T[i][j], T[i-1][k] + max_tasks_second_day ));
          }
      }
  }
  
  if (T[d][num_tasks] >= std::numeric_limits<int>::max())
    return -1;
  return T[d][num_tasks];
}
