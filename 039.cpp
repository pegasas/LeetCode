#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(vector<int> candidates, int start, int target, vector<int> items, vector<vector<int>>& res) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(items);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            items.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i], items, res);
            items.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> items;
        dfs(candidates, 0, target, items, res);
        return res;
    }
};

int main()
{
    return 0;
}