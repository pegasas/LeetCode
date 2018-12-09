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
    int jump(vector<int>& nums) {
        int i=0,j=1;
        int steps=0;
        int Size=nums.size();
        while(j<Size)
        {
            int end=min(nums[i]+i+1,Size);
            while(j<end)
            {
                if(nums[j]+j>nums[i]+i)i=j;
                j++;
            }
            steps++;
        }
        return steps;
    }
};


int main() {
    return 0;
}