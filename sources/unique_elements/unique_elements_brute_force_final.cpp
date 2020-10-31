bool unique_elements_final(const std::string &s)
{
  constexpr size_t ALPH_SIZE = 128;

  if (s.size() > ALPH_SIZE)
    return false;

  std::array<bool, ALPH_SIZE> F = { false };
  for (size_t i = 0; i < ALPH_SIZE; i++)
  {
    const int idx = s[i] - 'a';
    if (F[idx])
      return false;
    F[idx] = true;
  }
  return true;
}