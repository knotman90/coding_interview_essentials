int string_to_int_negative(const std::string& s)
{
	if(s.size() == 0)
		return 0;
	const int sign = s[0] == '-' ? -1 : 1;
	//skip the first char if sign is specified
	const int start = (s[0] == '-') || (s[0] == '+') ? 1 : 0; 
	return sign * string_to_int1( std::string(begin(s)+start,end(s)) ); 
}