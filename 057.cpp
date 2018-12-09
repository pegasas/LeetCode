#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        vector<Interval> ret;
        ret.clear();

        vector<Interval> tmp;
        tmp.clear();

        int s = newInterval.start;
        int e = newInterval.end;
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i].end >= s && intervals[i].start <= e)
            { //可以合并的合并掉
                e = max(e, intervals[i].end);
                s = min(s, intervals[i].start);
            }
            else
            { //不能合并的区间
                tmp.push_back(intervals[i]);
            }
        }

        //按照区间起始位置大小升序排列
        int i = 0;
        while (i < tmp.size() && tmp[i].start < s)
        {
            ret.push_back(tmp[i]);
            ++i;
        }
        ret.push_back(Interval(s, e));
        while (i < tmp.size() && tmp[i].start >= e)
        {
            ret.push_back(tmp[i]);
            ++i;
        }

        return ret;
    }
};
int main() {
    return 0;
}