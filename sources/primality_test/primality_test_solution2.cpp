bool is_prime_simple(const int n)
{
    if (n == 1)
        return false;
    if (n % 2 == 0)
        return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}