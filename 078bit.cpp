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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        for(int S = 0; S < (1<<n); S++) {
            vector<int> tmp;
            for(int i = 0; i < n ; i++)
                if (S & (1<<i)) {
                    tmp.push_back(nums[i]);
                }
            result.push_back(tmp);
        }
        return result;
    }
};

int main() {
    return 0;
}
