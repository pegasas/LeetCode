#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& ret, vector<int> cur, vector<int> &candidates, int target, int index)
    {
        if(target==0)
        {
            ret.push_back(cur);
            return;
        }
        for(int i=index;i<candidates.size()&&candidates[i]<=target;i++)
        {
            if(i!=index&&candidates[i]==candidates[i-1])continue;
            cur.push_back(candidates[i]);
            dfs(ret,cur,candidates,target-candidates[i],i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ret;
        vector<int> cur;
        dfs(ret,cur,candidates,target,0);
        return ret;
    }
};

int main() {
    return 0;
}