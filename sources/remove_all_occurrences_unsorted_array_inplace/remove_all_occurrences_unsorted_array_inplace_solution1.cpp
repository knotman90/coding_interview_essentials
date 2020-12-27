template <typename T>
int remove_elements_unsorted_array_remove_STL(std::vector<T>& A, auto predicate)
{
  return std::distance(std::begin(A),
                       std::remove_if(std::begin(A), std::end(A), predicate));
}