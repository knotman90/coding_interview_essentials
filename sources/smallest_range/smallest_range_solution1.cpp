int smallest_range_I(const vector<int>& I, const int K) {
    const auto& [m,M]   = std::minmax_element(std::begin(I), std::end(I));
    const int d = (*M-K) - (*m+K);
    return std::max(0, d);
}