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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cur;
        for(int i=0;i<nums.size();i++)
        {
            vector<int>::iterator it=lower_bound(cur.begin(),cur.end(),nums[i]);
            if(it==cur.end())cur.push_back(nums[i]);
            else (*it)=nums[i];
        }
        return cur.size();
    }
};

int main() {
    return 0;
}
