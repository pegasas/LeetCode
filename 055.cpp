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
    bool canJump(vector<int>& nums) {
        int energy = 1;
        int count;
        for (count = 0; count < nums.size()&&energy; count++) {
            energy = max(energy - 1, nums[count]);
        }
        return count==nums.size();
    }
};


int main() {
    return 0;
}
