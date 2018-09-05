#include<bits/stdc++.h>
using namespace std;

/*
两个已经排序的数组num1,num2,长度分别为m,n
求num1与num2的中位数
*/
class Solution {
public:
    int getkth(vector<int>& nums1,vector<int>& nums2,int k)
    {
        int m=nums1.size(),n=nums2.size();

        if(m>n)return getkth(nums2,nums1,k);
        if(m==0)return nums2[k-1];
        if(k==1)return min(nums1[0],nums2[0]);

        int i=min(m,k/2),j=min(n,k/2);
        vector<int> nums3;
        if(nums1[i-1]>nums2[j-1])
        {
            nums3=nums2;
            for(int l=0;l<j;l++)nums2.erase(nums2.begin());
            int ret=getkth(nums1,nums2,k-j);
            nums2=nums3;
            return ret;
        }
        else
        {
            nums3=nums1;
            for(int l=0;l<i;l++)nums1.erase(nums1.begin());
            int ret=getkth(nums1,nums2,k-i);
            nums1=nums3;
            return ret;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m=nums1.size(),n=nums2.size();
        int l=(m+n+1)/2;
        int r=(m+n+2)/2;
        return (getkth(nums1,nums2,l)+getkth(nums1,nums2,r))/2.0;
    }
};

int main()
{
    return 0;
}
