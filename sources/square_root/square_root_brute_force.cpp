int square_root_brute_force(const int n)
{
	long i = 0;
	while(i*i<=n)
		i++;
	return i-1;
}