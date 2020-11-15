
using Combination = std::vector<int>;

auto all_combinations_helper(Combination& combination, const int d, const int curr_idx)
{
    if(combination.size() == d){
        //combination is read
        (combination)
        
    }

    if(curr_idx >= d)
        return;
    
    for(int i = curr_idx; i < d ; i++)
    {
        combination.push_back(i);
        
        combination_helper(combination, d-1, i+1);

        combination.pop_back();
    }
    
}


auto all_combinations(const int d, const int curr_idx,  Fn operation)
{
    Combination work_in_progress;
    work_in_progress.reserve(d);
    return foreach_combination_helper(work_in_progress,d,0, operation);
}
