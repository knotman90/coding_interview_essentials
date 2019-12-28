std::vector<int> wave(std::vector<int> &A) 
{
    std::vector<int> B(A);
    std::sort(begin(B), end(B));
    auto it = B.begin();
    for(auto it = B.begin(); it+1 < B.end() ; it+=2)
    {
        std::swap(*it, *(it+1));
    }
    return B;
}
