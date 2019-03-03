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
#include <climits>

using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        int l=n.size();
        set<long> candidates;
        // biggest, one more digit, 10...01
        candidates.insert((long)pow(10,l)+1);
        // smallest, one less digit, 9...9 or 0
        candidates.insert((long)pow(10,l-1)-1);
        long prefix=stol(n.substr(0,(l+1)/2));
        // the closest must be in middle digit +1, 0, -1, then flip left to right
        for(long i=-1;i<=1;i++)
        {
            string p=to_string(prefix+i);
            string pp=p+string(p.rbegin()+(l&1),p.rend());
            candidates.insert(stol(pp));
        }
        long num=stol(n),minDiff=LONG_MAX,diff,minVal;
        candidates.erase(num);
        for(set<long>::iterator it=candidates.begin();it!=candidates.end();it++)
        {
            diff=abs((*it)-num);
            if(diff<minDiff)
            {
                minDiff=diff;
                minVal=(*it);
            }
        }
        return to_string(minVal);
    }
};

class Solution {
public:
    string nearestPalindromic(string n) {
        int l = n.size();
        set<long> candidates;
        // biggest, one more digit, 10...01
        candidates.insert(long(pow(10, l)) + 1);
        // smallest, one less digit, 9...9 or 0
        candidates.insert(long(pow(10, l - 1)) - 1);
        // the closest must be in middle digit +1, 0, -1, then flip left to right
        long prefix = stol(n.substr(0, (l + 1) / 2));
        for ( long i = -1; i <= 1; ++i ) {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (l & 1), p.rend());
            candidates.insert(stol(pp));
        }
        long num = stol(n), minDiff = LONG_MAX, diff, minVal;
        candidates.erase(num);                  // cannot be itself
        for ( long val : candidates ) {
            diff = abs(val - num);
            if ( diff < minDiff ) {
                minDiff = diff;
                minVal = val;
            }
        }
        return to_string(minVal);
    }
};

int main() {
    return 0;
}
