unsigned exponentiation_fast( unsigned n,  unsigned k)
{
	if(k==0)
		return 1;
	if( k %2 ==0  )
	{
		const auto ans = exponentiation_fast(n,k/2);
		return ans*ans;
	}
	return n * exponentiation_fast(n,k-1);

}