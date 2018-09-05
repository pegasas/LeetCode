#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int num=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[num] != nums[i]) {
                num++;
                nums[num]=nums[i];
            }
        }
        num++;
        return num;
    }
};

int main()
{
    return 0;
}