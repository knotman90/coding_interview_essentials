template <typename T>
int remove_duplicates_STL(std::vector<T>& I)
{
  return std::distance(std::begin(I), std::unique(std::begin(I), std::end(I)));
}
