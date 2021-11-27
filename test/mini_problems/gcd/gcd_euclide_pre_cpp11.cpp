template <int x, int y>
struct GCDEuclidePreCpp11
{
  static const int gcd = GCDEuclidePreCpp11<y, x % y>::gcd;
};

template <int x>
struct GCDEuclidePreCpp11<x, 0>
{
  static const int gcd = x;
};
