template <class Fn>
void capitalize_words_first_letter_adj_find(std::string& s, Fn f)
{
  if (s.size() > 0 && !std::isspace(s.front()))
    s.front() = f(s.front());

  const auto p = [](const auto& x, auto& y) { return std::isspace(x) && !std::isspace(y); };
  auto it      = std::adjacent_find(begin(s), end(s), p);
  while (it != std::end(s))
  {
    it++;
    *it = f(*it);
    it  = std::adjacent_find(it, std::end(s), p);
  }
}