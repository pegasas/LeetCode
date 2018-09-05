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
    void dfs(int now, int n, vector<int> nums, vector<int> items, vector<bool> used, vector<vector<int>>& res) {
        if (now == n) {
            res.push_back(items);
            return;
        }
        for(int i = 0; i < n; i++) {
            if (!used[i]) {
                used[i]=true;
                items.push_back(nums[i]);
                dfs(now+1, n, nums, items, used, res);
                items.pop_back();
                used[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> items;
        vector<bool> used(nums.size());
        int n = nums.size();
        dfs(0, n, nums, items, used, res);
        return res;
    }
};

int main()
{
    return 0;
}