void go(int offset, int k) {
  if (k == 0) {
    pretty_print(combination);
    return;
  }
  for (int i = offset; i <= people.size() - k; ++i) {
    combination.push_back(people[i]);
    go(i+1, k-1);
    combination.pop_back();
  }
}


int maxChunksToSorted_bruteforce(std::vector<int>& arr)
{
    for(int i = 0)

}