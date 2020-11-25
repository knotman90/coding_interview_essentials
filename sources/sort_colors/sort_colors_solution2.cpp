void Solution::sort_colors_one_pass(vector<int> &A) {
    if(A.size() <= 1)
        return;
        
    int x = 0;
    int y = A.size()-1;
    int i = 1;
    while(i <= y)
    {

        if(A[i] == 0)
        {
            std::swap(A[x++], A[i++]);
        }else if (A[i] == 2)
        {
            std::swap(A[y--], A[i]);
        }else
            i++;
    }
    
}
