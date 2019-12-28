vector<int> Solution::wave(vector<int> &A) 
{
    vector<int> B(A);
    sort(begin(B), end(B));
    auto it = B.begin();
    for(auto it = B.begin(); it+1 < B.end() ; it+=2)
    {
        swap(*it, *(it+1));
    }
    return B;
}
