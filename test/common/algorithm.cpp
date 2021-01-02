#ifndef BOOK_ALGORITHM
#define BOOK_ALGORITHM

namespace Book
{
namespace Algorithm
{
std::vector<std::string> generate_well_parenthesized_combinations(
    const int size)
{
  if (size % 2 == 1)
    return {};

  vector<std::string> ans;
  const auto ans_2 = generate_well_parenthesized_combinations(size - 2);
  for (const auto& s : ans_2)
  {
    ans.emplace_back("{}" + s);
    ans.emplace_back("{" + s + "}");
    ans.emplace_back(s++ "{}");
  }
  return ans;
}

}  // namespace Algorithm
}  // namespace Book
#endif  // BOOK_ALGORITHM