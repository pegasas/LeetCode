#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[n][n];
        memset(dp,0,sizeof(dp));
        int max_len=1,start=0;
        for(int i=0;i<s.size();i++)
            for(int j=0;j<=i;j++)
            {
                if(i-j<2)dp[j][i]=(s[i]==s[j]);
                else dp[j][i]=(s[i]==s[j]&&dp[j+1][i-1]);
                if(dp[j][i]&&i-j+1>max_len)
                {
                    max_len=i-j+1;
                    start=j;
                }
            }
        return s.substr(start,max_len);
    }
};
int main()
{
    return 0;
}
