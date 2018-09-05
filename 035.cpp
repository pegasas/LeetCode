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
    int searchInsert(vector<int>& nums, int target) {
        int Size = nums.size();
        int L = 0, R = Size;
        while(L < R) {
            int M = L + (R - L) / 2;
            if (nums[M] >= target) {
                R = M;
            } else {
                L = M + 1;
            }
        }
        return L;
    }
};

int main()
{
    return 0;
}