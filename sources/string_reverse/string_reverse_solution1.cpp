void reverse_string_inplace(std::string& s)
{
	const int len = s.length();
	for(int i = 0 ; i < len/2 ; i++)
		swap(s[i], s[len-1-i]);
	
}