std::string nesting_depths(const std::vector<int>& D)
{
  std::stringstream ss;

  int prec = 0;
  for (int i = 0; i < D.size(); i++)
  {
    const int curr = D[i];

    char add = '(';
    if (curr == prec)
    {
      ss << curr;
      continue;
    }

    else if (curr < prec)

      add = ')';

    int diff = std::abs(curr - prec);
    while (diff--)
    {
      ss << add;
    }
    ss << curr;
    prec = curr;
  }

  while (prec--)
    ss << ')';

  return ss.str();
}
