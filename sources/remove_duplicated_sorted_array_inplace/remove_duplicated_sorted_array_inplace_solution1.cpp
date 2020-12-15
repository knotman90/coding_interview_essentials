template<typename T>
int remove_duplicates_constant_space(std::vector<T>& I) 
{
    const auto num_elements = I.size();
    if(num_elements<=1)
        return num_elements;
        
    
    int x = 0, y = 1;
    while(y < num_elements)
    {
        if(I[x] != I[y])
            I[++x] = std::move(I[y]);
        y++;
    }
    return x+1;    
}
