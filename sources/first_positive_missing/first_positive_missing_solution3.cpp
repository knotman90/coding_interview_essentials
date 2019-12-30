int divide_pos_neg(std::vector<int> N)
{
    int s = 0;
    int e = N.size() -1;
    while(s <= e)
    {
        while(s <= e && N[s] > 0)
            s++;
        while(s <= e && N[e] <= 0)
            e--;
        if(s >= e)
            break;
        
        std::swap(N[s], N[e]);
    }
    return s;
}

int first_positive_missing_constant_space(std::vector<int> N) 
{
    const int num_pos = divide_pos_neg(N);
    for(int i = 0 ; i < num_pos ; i++)
    {
        const int ni = abs(N[i]);
        if( ni > 0  &&  ni-1 < num_pos)
           N[ni-1]*=-1;
    }
    
    for(int i = 1 ; i < num_pos ; i++)
      if( N[i-1] >=0 )
          return i;
    return num_pos+1;
}