int smallest_range_I(const vector<int>& I, const int K) {
    const auto& [m,M]   = std::minmax_element(std::begin(A), std::end(A));
    const int d = (*M-K) - (*m+K);
    return std::max(0, d);
}