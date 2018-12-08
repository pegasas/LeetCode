#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int Size=nums.size();
        int i=0;
        while(i<Size)
        {
            if(nums[i]==i+1||nums[i]==nums[nums[i]-1]||nums[i]<=0||nums[i]>Size)
                i++;
            else
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(i=0;i<Size;i++)
            if(nums[i]!=i+1)
                break;
        return i+1;
    }
};

int main() {
    return 0;
}