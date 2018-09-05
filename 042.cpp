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
    int trap(vector<int>& height) {
        int size = height.size();
        int result = 0;
        if(size <= 0){
            return result;
        }//if
        int leftMax[size];
        int rightMax[size];
        leftMax[0] = 0;
        rightMax[size-1] = 0;
        // 对于第i个元素 左右最大值
        for(int i = 1;i < size;++i){
            leftMax[i] = max(leftMax[i-1],height[i-1]);
            rightMax[size-1-i] = max(rightMax[size-i],height[size-i]);
        }//for
        // 最大积雨量
        int h;
        for(int i = 0;i < size;++i){
            h = min(leftMax[i],rightMax[i]);
            if(h > height[i]){
                result += h - height[i];
            }//if
        }//for
        return result;
    }
};

int main()
{
    return 0;
}