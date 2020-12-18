#ifndef TEST_COMMON_TEST_UTILS
#define TEST_COMMON_TEST_UTILS

std::string to_string(const int& v)
{
    std::ostringstream ss;
     ss<<v;
    return ss.str();
}

std::string to_string(const std::pair<int,int>& q)
{
    std::ostringstream ss;
     ss<<"(";
        ss<<std::get<0>(q);
        ss<<",";
        ss<<std::get<1>(q);
        ss<<") ";
        return ss.str();
}

template<typename T>
std::string to_string(const std::vector<T>& Q )
{
    std::ostringstream ss;
    ss<<"[";
    for(const auto& q: Q){
        ss<<to_string(q);
        ss<<", ";
    }
    ss<<"]";
    return ss.str();
}

#endif /* TEST_COMMON_TEST_UTILS */
