double mediam_sorted_arrays_naive(const std::vector<int> &A,
                                  const std::vector<int> &B)
{
  std::vector<int> C(A);
  C.insert(std::end(C), std::begin(B), std::end(B));
  std::sort(std::begin(C), std::end(C));
  
  const auto mid = C.size() / 2;
  return (C.size() & 1) ? C[mid] 
                        : (C[mid] + C[mid + 1]) / 2.0;
}