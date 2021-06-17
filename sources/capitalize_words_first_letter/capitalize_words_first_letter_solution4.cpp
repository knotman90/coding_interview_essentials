void capitalize_words_first_letter_simple(std::string& s)
{
  if (s.empty())
    return;

  // first char: to upper if not a space
  if (!std::isspace(s[0]))
    s[0] = std::toupper(s[0]);

  // rest of the string
  for (int i = 1; i < std::ssize(s); i++)
  {
    if (!std::isspace(s[i ]) && std::isspace(s[i - 1]))  // if the previous char is a space
      s[i] = std::toupper(s[i]);
  }
}