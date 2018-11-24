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
    //使用深度优先的回溯法
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(),nums.end());
        result.push_back(path);
        dfs(nums,0,path,result);
        return result;
    }
    void dfs(vector<int>& nums,int pos,vector<int> & path,vector<vector<int>> & result)
    {
        if(pos==nums.size())
            return;

        for(int i=pos;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            result.push_back(path);
            dfs(nums,i+1,path,result);
            path.pop_back();
        }
    }
};

int main() {
    return 0;
}
