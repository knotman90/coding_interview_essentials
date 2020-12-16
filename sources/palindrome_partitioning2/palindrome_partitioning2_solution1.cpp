#include "generate_combinations.h"

bool is_palindrome(const std::string&s, const size_t start, const size_t end)
{
	assert(start <= end);
	assert(end < s.length());

	auto l = start, r = end;
	while(l < r)
		if(s[l--]!=s[r--])
			return false;
	return true;
}

int palindrome_partitioning2_bruteforce(const std::string s)
{
	
}