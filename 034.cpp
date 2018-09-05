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
    vector<int> searchRange(vector<int>& nums, int target) {
        int Size = nums.size();
        vector<int> ret;
        if (Size == 0) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        int L = 0, R = Size;
        while(L < R) {
            int M = L + (R - L) / 2;
            if (nums[M] >= target) {
                R = M;
            } else {
                L = M + 1;
            }
        }
        if (L < Size && nums[L] == target) {
            ret.push_back(L);
        }
        L = 0, R = Size;
        while(L < R) {
            int M = L + (R - L) / 2;
            if(nums[M] <= target) {
                L = M + 1;
            } else {
                R = M;
            }
        }
        if (L >= 1 && nums[L - 1] == target) {
            ret.push_back(L - 1);
        }
        if (ret.size() == 0) {
            ret.push_back(-1);
            ret.push_back(-1);
        }
        return ret;
    }
};

int main()
{
    return 0;
}