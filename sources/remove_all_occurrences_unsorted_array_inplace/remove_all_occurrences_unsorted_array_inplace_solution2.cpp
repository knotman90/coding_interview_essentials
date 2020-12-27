template <typename T>
int remove_elements_unsorted_array_linear_space(std::vector<T>& A,
                                                auto predicate)
{
  std::vector<int> temp;
  std::copy_if(std::begin(A),
               std::end(A),
               std::back_inserter(temp),
               std::not_fn(predicate));
  std::copy(std::begin(temp), std::end(temp), std::begin(A));
  return temp.size();
}
