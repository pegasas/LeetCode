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
    int maxSubArray(vector<int>& nums) {
        int maxCur = nums[0], maxSoFar = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxCur = max(nums[i], maxCur += nums[i]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};

int main() {
    return 0;
}
