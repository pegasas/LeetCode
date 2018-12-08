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
    void combinationSum(vector<int>& candidates,int target,int index,vector<vector<int>>& res,vector<int> soFar)
    {
        if(target==0)
        {
            res.push_back(soFar);
            return;
        }
        if(index>=candidates.size())return;
        int candidate=candidates[index];
        for(int num=0;num*candidate<=target;num++)
        {
            if(num>0)soFar.push_back(candidate);
            combinationSum(candidates,target-num*candidate,index+1,res,soFar);
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> soFar;
        combinationSum(candidates,target,0,res,soFar);
        return res;
    }
};

int main() {
    return 0;
}