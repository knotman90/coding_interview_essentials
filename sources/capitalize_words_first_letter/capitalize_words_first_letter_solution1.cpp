void capitalize_words_first_letter_iterator(std::string &s)
{
  auto it = begin(s);
  while (it != end(s))
  {
    //(1) skip all spaces
    while (it != end(s) && *it == ' ')
      it++;
    //(2) to_upper
    if (it != end(s))
      *it = toupper(*it);

    //(3) skip the rest of the word
    while (it != end(s) && *it != ' ')
      it++;
  }
}