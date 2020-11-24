template<typename T>
int remove_duplicates_STL(std::vector<T>& I) 
{
    const auto end_unique_it = std::unique(std::begin(I), std::end(I));
    return std::distance(std::begin(I), end_unique_it );
}
