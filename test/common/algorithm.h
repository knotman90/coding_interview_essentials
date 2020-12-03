#ifndef BOOK_ALGORITHM
#define BOOK_ALGORITHM
#include <random>

namespace Book
{
namespace Algorithm
{
using std::string;
using std::vector;



template<typename T, typename = std::enable_if<std::is_integral<T>::value>::type>
T get_random_in_range(const T& s, const T& e)
{
	static std::random_device dev;
    static std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(s,e);

    return dist(rng);
}


void generate_well_parenthesized_combinations_helper(vector<std::string>& ans,
                                                     string& s,
                                                     const int pos,
                                                     const int size,
                                                     const int open,
                                                     const int closed)
{
  if (closed == size)
  {
    ans.push_back(s);
    return;
  }

  if (open > closed)
  {
    s[pos] = ')';
    generate_well_parenthesized_combinations_helper(ans, s, pos + 1, size, open, closed + 1);
  }
  if (open < size)
  {
    s[pos] = '(';
    generate_well_parenthesized_combinations_helper(ans, s, pos + 1, size, open + 1, closed);
  }
}

std::vector<std::string> generate_well_parenthesized_combinations(const int size)
{
  vector<std::string> ans;
  std::string s;
  s.resize(size * 2);
  generate_well_parenthesized_combinations_helper(ans, s, 0, size, 0, 0);
  return ans;
}


/**
 * Generate a collection of random integrals
 * 
 **/
template<typename T>
auto generateRandomCollection(const int size, const int l , const int r )
{
  std::vector<T> ans;
  ans.reserve(size);
  for(int i = 0 ; i < size ; i++)
  {
    ans.emplace_back(Book::Algorithm::get_random_in_range(l,r));
  }
  return ans;
}


}  // namespace Algorithm
}  // namespace Book
#endif  // BOOK_ALGORITHM