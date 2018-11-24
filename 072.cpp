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
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length(),cost;
        //int[][] dp = new int [n+1][m+1];
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        //初始化
        for(int i=0;i<=n;i++)
            dp[i][0]=i;
        for(int i=0;i<=m;i++)
            dp[0][i]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                cost = word1[i-1] == word2[j-1] ? 0 : 1;
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + cost);
            }
        }
        return dp[n][m];
    }
};




int main() {
    return 0;
}
