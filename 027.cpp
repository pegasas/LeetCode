#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ret;
        for(int i=0;i<nums.size();i++) {
            if (nums[i] != val) {
                ret.push_back(nums[i]);
            }
        }
        nums = ret;
        return nums.size();
    }
};

int main()
{
    Solution s;
    int a[]={3,2,2,3};
    vector<int> b(a,a+4);
    cout<<s.removeElement(b,3)<<endl;
    return 0;
}