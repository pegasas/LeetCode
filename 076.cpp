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

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for(int i = 0;i < t.size(); i++) map[t[i]]++;
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head=0;
        while(end < s.size()) {
            if (map[s[end]] > 0) {
                counter--;
            }
            map[s[end]]--;
            end++;
            while(counter == 0) {
                if (end - begin < d) {
                    d = end - begin;
                    head = begin;
                }
                if(map[s[begin]] == 0)counter++;
                map[s[begin]]++;
                begin++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};


int main() {
    return 0;
}
