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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n=dungeon[0].size();
        vector<int> dp(n+1, INT_MAX);
        dp[n-1] = 1;
        for(int i = m-1; i>=0; i--)
            for(int j =n-1; j>=0; j--)
                dp[j] = max(min(dp[j], dp[j+1])-dungeon[i][j], 1);
        return dp[0];
    }
};

int main() {
    return 0;
}
