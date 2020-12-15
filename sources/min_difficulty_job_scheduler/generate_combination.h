using Combination = std::vector<int>;
using CombinationList = std::vector<Combination>;

void all_combinations_helper(CombinationList& all_combinations, Combination& combination, const unsigned d, const int curr_idx, const unsigned limit)
{
    if(combination.size() == d){
        //combination is ready
        all_combinations.push_back(combination);
        return;   
    }
   
    for(size_t i = curr_idx; i < limit ; i++)
    {
        combination.push_back(i);
        all_combinations_helper(all_combinations,combination, d, i+1, limit);
        combination.pop_back();
    }
    
}

auto all_combinations(const unsigned d, const unsigned limit)
{
    Combination work_in_progress;
    work_in_progress.reserve(d);
    CombinationList all_combinations;
    //limit -1 because the last cut cannot be empty
    all_combinations_helper(all_combinations,work_in_progress,d,0,limit-1 );
    return all_combinations;
}