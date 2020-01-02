bool is_prime_final(const int n)
{
    if (n == 1)
        return false;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}