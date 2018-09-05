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
    int search(vector<int>& nums, int target) {
        int Size = nums.size();
        if (Size == 0) {
            return -1;
        }
        int left = 0, right = Size - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[left]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid + 1] <= target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        if (nums[left] == target) {
            return left;
        }
        else {
            return -1;
        }
    }
};

int main()
{
    Solution s;
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    cout<<s.search(a,3)<<endl;
    return 0;
}