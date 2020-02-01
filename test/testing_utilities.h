template <template <typename> typename Cont, typename T>
std::ostream &operator<<(std::ostream &os, const Cont<T> &v)
{
  using namespace std;
  copy(begin(v), end(v), ostream_iterator<T>(os, " "));
  os << "\n";
  return os;
}