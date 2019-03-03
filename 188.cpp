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
private:
    vector<int> local[2], global[2];
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        if(n <= 1) {
            return 0;
        }

        if(k >= n) {
            return maxProfit2(prices);
        }

        for(int i = 0; i < 2; i++) {
            local[i].assign(k + 1, 0);
            global[i].assign(k + 1, 0);
        }
        int pre = 0, now;
        for(int i = 1; i < n; i++) {
            int diff = prices[i] - prices[i - 1];
            now = 1 - pre;
            for(int j = 1; j <= k; j++) {
                local[now][j] = max(local[pre][j] + diff, global[pre][j - 1] + max(0, diff));
                global[now][j] = max(global[pre][j], local[now][j]);
            }
            pre = now;
        }
        return global[now][k];
    }
    int maxProfit2(vector<int>& prices) {
        int result = 0;
        int n = prices.size();
        for(int i = 1; i < n; i++) {
            if(prices[i] > prices[i-1])
                result += prices[i] - prices[i - 1];
        }
        return result;
    }
};

int main() {
    return 0;
}
