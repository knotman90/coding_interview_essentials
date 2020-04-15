int find_majority_element_median(std::vector<int>& N)
{
  if(N.size() == 0)
    return -1; 
  std::sort(std::begin(N),std::end(N));
  const int midpoint = N.size()/2;
  const int el = N[midpoint];
  
  const size_t threshold = N.size() / 2;
  if (std::count(begin(N), end(N), el) > threshold)
    return el;
  return -1;
}
