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

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        for(int i=1;i<nums.size()&&cnt<=1;i++)
        {
            if(nums[i-1]>nums[i])
            {
                cnt++;
                if(i-2<0||nums[i-2]<=nums[i])
                    nums[i-1]=nums[i];
                else
                    nums[i]=nums[i-1];
            }
        }
        return cnt<=1;
    }
};

int main() {
    return 0;
}
