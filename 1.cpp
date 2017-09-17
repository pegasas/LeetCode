/*
题目大意：给数组nums,求nums中两个数相加为target
答案：
扫描一维索引一维
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums,int target)
    {
        map<int,int> Map;
        Map.clear();
        for(int i=0;i<nums.size();i++)Map[nums[i]]=i;
        for(int i=0;i<nums.size();i++)
        {
            int findnum=target-nums[i];
            if(Map.find(findnum)!=Map.end())
                if(Map[findnum]!=i)
                {
                    vector<int> result;
                    result.clear();
                    result.push_back(i);
                    result.push_back(Map[findnum]);
                    return result;
                }
        }
    }
};

int main()
{
    return 0;
}
