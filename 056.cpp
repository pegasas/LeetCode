#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#define LL long long

using namespace std;


struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
    static bool cmp (const Interval& I1, const Interval& I2) {
        return I1.start < I2.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() == 0) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int L = intervals[0].start, R = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++) {
            if (R >= intervals[i].start) {
                R = max(R, intervals[i].end);
            } else {
                result.push_back(Interval(L, R));
                L = intervals[i].start;
                R = intervals[i].end;
            }
        }
        result.push_back(Interval(L, R));
        return result;
    }
};


int main() {
    return 0;
}
