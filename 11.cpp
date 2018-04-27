#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int left=0,right=height.size()-1;
        int Max=0;
        while(left<right)
        {
            Max=max(Max,min(height[left],height[right])*(right-left));
            if(height[left]<height[right])left++;
            else right--;
        }
        return Max;
    }
};
int main()
{
    return 0;
}
