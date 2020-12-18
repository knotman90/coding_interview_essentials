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

template<typename T>
auto generate_random_pair_in_range(const T s, const T e)
{
    assert(s<=e);
     auto M = Book::Algorithm::get_random_in_range<T>(s,e);
     auto m = Book::Algorithm::get_random_in_range<T>(s,e);
    if(M < m)
        swap(M,m);
    return std::pair<T,T>(m,M);
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

}  // namespace Algorithm
}  // namespace Book
#endif  // BOOK_ALGORITHM