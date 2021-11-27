using Matrix = std::vector<std::vector<int>>;

bool advanceRight(std::pair<size_t, size_t>& rightPtr,
                  const std::pair<size_t, size_t>& downPtr,
                  const size_t n,
                  const size_t m)
{
  rightPtr.second++;
  if (rightPtr.second >= m)
  {
    rightPtr.second = downPtr.second + 1;
    rightPtr.first++;
  }
  return rightPtr.first < n && rightPtr.second < m;
}

bool advanceDown(std::pair<size_t, size_t>& downPtr,
                 const std::pair<size_t, size_t>& rightPtr,
                 const size_t n,
                 const size_t m)
{
  downPtr.first++;
  if (downPtr.first >= n)
  {
    downPtr.first = rightPtr.first + 1;
    downPtr.second++;
  }
  return downPtr.second < m && downPtr.first < n;
}

int kth_smallest_in_sorted_matrix_brute_force_constant_space(const Matrix& M,
                                                             const size_t k)
{
  const size_t n                     = M.size();
  const size_t m                     = M[0].size();
  size_t steps                       = 0;
  std::pair<size_t, size_t> rightPtr = {0, 1};
  std::pair<size_t, size_t> downPtr  = {0, 0};
  bool stopDown = false, stopRight = !(rightPtr.second < m);
  while (!stopRight && !stopDown)
  {
    const auto valDown  = M[downPtr.first][downPtr.second];
    const auto valRight = M[rightPtr.first][rightPtr.second];
    if (steps == (k - 1))
    {
      return std::min(valDown, valRight);
    }
    if (valDown <= valRight)
    {
      stopDown = !advanceDown(downPtr, rightPtr, n, m);
    }
    else
    {
      stopRight = !advanceRight(rightPtr, downPtr, n, m);
    }
    steps++;
  }

  while (!stopRight)
  {
    if (steps == (k - 1))
    {
      return M[rightPtr.first][rightPtr.second];
    }
    stopRight = !advanceRight(rightPtr, downPtr, n, m);
    steps++;
  }

  while (!stopDown)
  {
    if (steps == (k - 1))
    {
      return M[downPtr.first][downPtr.second];
    }
    stopDown = !advanceDown(downPtr, rightPtr, n, m);
    steps++;
  }

  throw std::invalid_argument(std::string("Invalid Input for k = ")
                              + std::to_string(k));
}