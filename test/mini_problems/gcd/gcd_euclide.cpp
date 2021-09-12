int gcd_euclide(const int x, const int y)
{
    if((x%y==0))
        return y;
    
    const auto reminder = x%y;
    return gcd_euclide(y,reminder);

}

