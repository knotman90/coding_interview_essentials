vector<vector<int>> power_set_2(const vector<int>& A)
{
	const size_t limit = (1ll<<A.size())-1;    
	vector<vector<int>> PS;
	PS.push_back({});
	
	size_t lim = 1;
	for(const auto a : A)
	{
		for(int i = 0 ; i < lim ; i++)
		{
			vector<int> subset = PS[i];
			subset.push_back(a);
			PS.push_back(subset);            
		}
		lim = PS.size();
	}
	
	return PS;    
}