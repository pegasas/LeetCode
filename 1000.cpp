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
#include <unordered_map>
#include <list>
#include <cstring>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n - 1) % (K - 1)) return -1;
        // change to 1-base stones
        vector<int> newStones;
        newStones.push_back(0);
        for(int i = 0; i < stones.size(); i++)newStones.push_back(stones[i]);

        vector<int> sum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + newStones[i];
        }

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(K + 1, 1e9)));
        for(int i = 1; i <= n; i++) {
            dp[i][i][1] = 0;
        }

        for(int L = 2; L <= n; L++) {
            for(int i = 1; i + L - 1 <= n; i++) {
                int j = i + L - 1;
                for(int k = 2; k <= K; k++) {
                    for(int j1 = i; j1 < j; j1 += K - 1) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i][j1][1] + dp[j1 + 1][j][k - 1]);
                    }
                }
                dp[i][j][1] = dp[i][j][K] + sum[j] - sum[i - 1];
            }
        }

        return dp[1][n][1];
    }
};

//class Solution {
//public:
//    int mergeStones(vector<int>& stones, int K) {
//        const int n = stones.size();
//        if ((n - K) % (K - 1))
//            return -1;
//        // calculate the sum from 0 to i
//        vector<int> sumStones(n + 1, 0);
//        for (auto i = 0; i < n; ++i) {
//            sumStones[i + 1] = sumStones[i] + stones[i];
//        }
//        // initialize the 3d vector dp
//        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K + 1, 1e9)));
//        for (int i = 0; i < n; ++i) {
//            dp[i][i][1] = 0;
//        }
//        // compute the transition functions
//        for (auto stepLen = 2; stepLen <= n; ++stepLen) {
//            for (auto i = 0; i <= n - stepLen; ++i) {
//                int j = i + stepLen - 1;
//                for (auto k = 2; k <= K; k++) {
//                    for ( auto m = i; m < j; m += K - 1) {
//                        dp[i][j][k] = min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
//                    }
//                }
//                dp[i][j][1] = dp[i][j][K] + sumStones[j + 1] - sumStones[i];
//            }
//        }
//        return dp[0][n - 1][1];
//    }
//};

int main() {

}
