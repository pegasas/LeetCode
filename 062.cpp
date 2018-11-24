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
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m,vector<int>(n,0));
        for (int i = 0; i < n; i++) path[0][i] = 1;
        for (int i = 0; i < m; i++) path[i][0] = 1;
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                path[j][i] = path[j - 1][i] + path[j][i - 1];
        return path[m - 1][n - 1];
    }
};

int main() {
    return 0;
}
