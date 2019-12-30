int first_positive_missing_linear_space(std::vector<int> A)
{
	std::vector<bool> F(A.size(), false);

	for(const auto& x : A){
		if(x >=0 && x < A.size())
			F[x] = true;
	}
	for(size_t i = 0; i < F.size() ; i++)
		if(!F[i])
			return i;

	return A.size();	
}