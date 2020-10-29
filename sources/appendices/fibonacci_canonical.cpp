unsigned F(const unsigned n)
{
    assert(n>=0);
    if(n <= 1) return n;

    return F(n-1)+F(n-2);
}