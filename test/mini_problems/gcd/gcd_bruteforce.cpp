int gcd_bruteforce(const int x, const int y)
{
    if(x < y )
        return gcd_bruteforce(y,x);
    
    for(int i = y ; i > 1 ; i--)
        if((x%i ==0)  && (y%i==0))
            return i;
    return 1;
}