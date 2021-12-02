int odd_appearing_element_final_std(const std::vector<int> &A)
{
  return std::accumulate(std::begin(A),
                         std::end(A),  // range
                         0,            // initial value
                         [](const int acc, const int x) {
                           return acc ^ x;
                         }  // binary reduction operation
  );
}