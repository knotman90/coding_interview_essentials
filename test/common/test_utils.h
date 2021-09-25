#ifndef TEST_COMMON_TEST_UTILS
#define TEST_COMMON_TEST_UTILS

#include "merge_intervals_2/Interval.h"

#define EXPECT_EQUAL_ELEMENTS(x, y)                                           \
  do                                                                          \
  {                                                                           \
    EXPECT_EQ(x.size(), y.size()) << "Vectors x and y are of unequal length"; \
    for (size_t i = 0; i < x.size(); ++i)                                        \
    {                                                                         \
      EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;       \
    }                                                                         \
  } while (0);


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

std::string to_string(const Interval& q)
{
    return to_string(std::pair(q.start,q.end));
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
