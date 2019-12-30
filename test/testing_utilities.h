template<typename T>
std::ostream &operator <<(std::ostream &os, const std::vector<T> &v) {
    using namespace std;
    copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
    os<<"\n";
    return os;
}