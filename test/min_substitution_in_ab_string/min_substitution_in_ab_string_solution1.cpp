int skip(const std::string& s, int& pos, const char c)
{
  int count = 0;
  while (pos < s.size())
  {
    if (s[pos] == c)
    {
      pos++;
      count++;
    }
    else
    {
      break;
    }
  }
  return count;
}

void min_substitution_in_ab_string(std::string& s, int pos, int& max_cons)
{
  const int initial_pos = pos;
  if (pos >= s.size())
    return;
  int ans = 1;

  skip(s, pos, '?');
  if (pos >= s.size())
    return;

  // now we either have 'a' or 'b'
  int count   = 0;
  char letter = s[pos];
  while (pos < s.size() && s[pos] != '?')
  {
    letter   = s[pos];
    count    = skip(s, pos, letter);
    max_cons = std::max(max_cons, count);
  }
  // at this point letter^count followed by ?
  // count the ?
  int countQ = skip(s, pos, '?');

  // at this point either
  // - the string is finished = we are done
  if (pos >= s.size())
    return;
  // - we have another character
  // we count how many times it occurs
  int countRight   = 0;
  char letterRight = s[pos];
  while (pos < s.size() && s[pos] == letterRight)
  {
    letterRight = s[pos];
    countRight  = skip(s, pos, letterRight);
    max_cons    = std::max(max_cons, count);
  }
  // letter^count ?^countQ letterRight^countRight
  if (letter == letterRight)
  {
    if (countQ % 2 == 0)
    {  // even
      max_cons = std::max(max_cons, 2);
      return min_substitution_in_ab_string(
          s, initial_pos + count + countQ, max_cons);
    }
    else
    {  // odd
      return min_substitution_in_ab_string(
          s, initial_pos + count + countQ, max_cons);
    }
  }
  else
  {
    if (countQ % 2 == 0)
    {  // even
      return min_substitution_in_ab_string(
          s, initial_pos + count + countQ, max_cons);
    }
    else
    {  // odd
      if (countQ == 1)
      {
        if (count <= countRight)
        {
          max_cons = std::max(max_cons, count + 1);
          return min_substitution_in_ab_string(
              s, initial_pos + count + countQ, max_cons);
        }
        else
        {
          // max is already count
          s[initial_pos + count + countQ - 1] = letterRight;
          return min_substitution_in_ab_string(
              s, initial_pos + count + countQ-1, max_cons);
        }
      }
      else
      {
          max_cons = std::max(max_cons, 2);
        return min_substitution_in_ab_string(
            s, initial_pos + count + countQ, max_cons);
      }
    }
  }
}

int min_substitution_in_ab_string(std::string s)
{
  int max_cons = 1;
  min_substitution_in_ab_string(s, 0, max_cons);
  return max_cons;
}