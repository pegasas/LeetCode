#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows)
    {
        int len=s.length();
        if(len==0||numRows<2)return s;
        string ret="";
        int lag=2*numRows-2;
        for(int i=0;i<numRows;i++)
            for(int j=i;j<len;j+=lag)
            {
                ret+=s[j];
                if(i>0&&i<numRows-1)
                {
                    int t=j+lag-2*i;
                    if(t<len)ret+=s[t];
                }
            }
        return ret;
    }
};
int main()
{
    return 0;
}
