
int calculate_cost_schedule(const std::vector<int>& I, const std::vector<int>& cutpoints_combo)
{

    int ans = 0;
    auto start = std::begin(I);
    for(const auto& cutpoint : cutpoints_combo){
        const auto finish = std::begin(I) + cutpoint+1;
        ans += *std::max_element(start, finish);
        start = finish;
    }
    ans += *std::max_element(start, std::end(I));
    return ans;
}

int min_difficulty_scheduler_combinations(const std::vector<int>& I, const unsigned d)
{
    if( I.size() < d)
        return -1;

    auto all_combinations_cutpoints = all_combinations(d-1, I.size());
    int ans = std::numeric_limits<int>::max();
    for(const auto& cutpoints_combo : all_combinations_cutpoints)
    {
        ans = std::min(ans, calculate_cost_schedule(I, cutpoints_combo));
    }
    return ans;
}