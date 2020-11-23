int removeDuplicates(std::vector<int> I) 
{
    if(I.size()<=1)
        return n1;
        
    
    int x = 0, y = 1;
    while(j < I.size())
    {
        if(A[x] != A[y])
            A[x++]  = A[y];
        y++;
    }
    return x+1;    
}
