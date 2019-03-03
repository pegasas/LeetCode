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
#include <deque>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size(),m = n/2;
        int totalSum = accumulate(A.begin(), A.end(), 0);
        bool isPossible = false;
        for (int i = 1;i <= m; i++)
            if (totalSum * i % n == 0) {
                isPossible = true;
                break;
            }
        if(!isPossible) {
            return false;
        }

        vector<unordered_set<int>> sums(m+1);
        sums[0].insert(0);
        for (int i = 0; i < A.size(); i++) {
            for (int j = min(m, i+1); j >= 1; j--) {
                for(unordered_set<int>::iterator it = sums[j - 1].begin(); it != sums[j - 1].end(); it++) {
                    sums[j].insert(A[i] + (*it));
                }
            }
        }

        for (int i = 1; i <= m; i++) {
            if (totalSum * i % n == 0 && sums[i].find(totalSum * i / m) != sums[i].end()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
