#ifndef TEST_MERGE_INTERVALS_2_INTERVAL
#define TEST_MERGE_INTERVALS_2_INTERVAL
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
#endif /* TEST_MERGE_INTERVALS_2_INTERVAL */
