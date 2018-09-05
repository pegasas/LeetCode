#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        int Size=num.size();
        sort(num.begin(),num.end());
        for(int i=0;i<Size;i++)
        {
            while(i>0&&i<Size&&num[i]==num[i-1])i++;
            int j=i+1;
            int k=Size-1;
            while(j<k)
            {
                int sum=num[i]+num[j]+num[k];
                if(sum==0)
                {
                    vector<int> cur;
                    cur.push_back(num[i]);
                    cur.push_back(num[j]);
                    cur.push_back(num[k]);
                    ret.push_back(cur);
                    j++;k--;
                    while(j<k&&num[j]==num[j-1])j++;
                    while(j<k&&num[k]==num[k+1])k--;
                }
                else if(sum<0)
                {
                    j++;
                    while(j<k&&num[j]==num[j-1])j++;
                }
                else
                {
                    k--;
                    while(j<k&&num[k]==num[k+1])k--;
                }
            }
        }
        return ret;
    }
};
int main()
{
    return 0;
}
