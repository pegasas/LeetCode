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

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int N = A.size();
        int res = A[N-1] - A[0];
        for (int i = 0; i < N - 1; i++) {
            res = min(res, max(A[N-1], A[i] + 2*K) - min(A[i+1], A[0] + 2*K));
        }
        return res;
    }
};

int main() {
    return 0;
}
