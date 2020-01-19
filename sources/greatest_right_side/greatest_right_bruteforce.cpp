void greatest_right_bruteforce(std::vector<int> &A) {
  for (size_t i = 0; i < A.size(); i++) {
    const auto greatest = max_element(begin(A) + i + 1, end(A));
    A[i] = (greatest != end(A)) ? *greatest : -1;
  }
}