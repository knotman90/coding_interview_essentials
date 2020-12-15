#include <cassert>
template <typename T>
std::vector<T> mergeSortedArrays(const std::vector<T> &A,
                                 const std::vector<T> &B)
{
  assert(std::is_sorted(std::begin(A), std::end(A)));
  assert(std::is_sorted(std::begin(B), std::end(B)));

  const int size = A.size() + B.size();
  std::vector<int> C;
  C.reserve(size);

  auto itA = std::begin(A);
  auto itB = std::begin(B);

  while (itA != std::end(A) && itB != std::end(B))
  {
    if (*itA < *itB)
      C.push_back(*itA++);
    else
      C.push_back(*itB++);
  }

  while (itA != std::end(A))
    C.push_back(*itA++);

  while (itB != std::end(B))
    C.push_back(*itB++);
  return C;
}

double mediam_sorted_arrays_merge(const std::vector<int> &A,
                                  const std::vector<int> &B)
{
  std::vector<int> C = mergeSortedArrays(A, B);

  const int mid = C.size() / 2;
  return (C.size() & 1) ? C[mid] : (C[mid] + C[mid + 1]) / 2.0;
}