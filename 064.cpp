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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n;
        if(!m)  return 0;
        else    n = grid[0].size();
        vector<vector<int>> path(m,vector<int>(n,0));
        path[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
            path[0][i] = grid[0][i] + path[0][i - 1];
        for (int i = 1; i < m; i++)
            path[i][0] = grid[i][0] + path[i - 1][0];
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                path[j][i] = grid[j][i] + min(path[j - 1][i],path[j][i - 1]);
        return path[m - 1][n - 1];
    }
};


int main() {
    return 0;
}
