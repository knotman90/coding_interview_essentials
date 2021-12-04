int count_conforming(const unsigned N)
{
    const int zeros = 30 - std::popcount<unsigned int>(N);
  return 1 << zeros;
}
int solve(const unsigned A, const unsigned B, const unsigned C)
{
  return count_conforming(A) + count_conforming(B) + count_conforming(C)
         - count_conforming(A | B) - count_conforming(A | C)
         - count_conforming(B | C) + count_conforming(A | B | C);
}