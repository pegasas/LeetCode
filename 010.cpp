#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s,string p)
    {
        if(s==null||p==null)return false;

        bool **dp=new bool*[s.length()+1];
        for(int i=0;i<s.length()+1;i++)dp[i]=new bool[p.length()+1];

        dp[0][0]=true;
        for(int j=0;j<p.length();j++)
            if(p[j]=='*'&&dp[0][j-1])
                dp[0][j+1]=true;

        for(int i=0;i<s.length();i++)
            for(int j=0;j<p.length();j++)
            {
                if(p[j]=='.')dp[i+1][j+1]=dp[i][j];
                if(s[i]==p[j])dp[i+1][j+1]=dp[i][j];
                if(p[j]=='*')
                {
                    if(p[j-1]!=s[i]&&p[j-1]!='.')dp[i+1][j+1]=dp[i+1][j-1];
                    else dp[i+1][j+1]=(dp[i+1][j]|dp[i][j+1]|dp[i+1][j-1]);
                }
            }
        return dp[s.length()][p.length()];
    }
};

int main()
{
    return 0;
}
