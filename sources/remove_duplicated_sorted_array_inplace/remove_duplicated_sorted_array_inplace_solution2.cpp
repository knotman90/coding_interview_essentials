template<typename T>
int remove_duplicates_linear_space(std::vector<T>& I) 
{
    const auto num_elements = I.size();
    if(num_elements<=1)
        return num_elements;
        
    
    std::unordered_set<T> inserted;
    std::vector<T> I_uniques;
    for(const auto& x : I)
    {
        if(!inserted.contains(x))
        {
            inserted.insert(x);
            I_uniques.push_back(x);
        }
    }
    std::copy(std::begin(I_uniques), std::end(I_uniques), std::begin(I));
    return I_uniques.size();
}
