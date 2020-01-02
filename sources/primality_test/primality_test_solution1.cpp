bool is_prime_brute_force(const int n)
{
    if (n == 1 || n == 2)
        return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}