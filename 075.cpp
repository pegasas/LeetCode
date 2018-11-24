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
    void sortColors(vector<int>& nums) {
        int Size = nums.size();
        int red = 0, blue = Size - 1;
        for(int i = 0; i <= blue; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[red]);
                red++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[blue]);
                i--;
                blue--;
            }
        }
    }
};



int main() {
    return 0;
}
