#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s)
    {
        int n=s.size();
        string ret(2*n+2,'\0');
        ret[0]='$';
        ret[1]='#';
        int j=2;
        for(int i=0;i<n;i++)
        {
            ret[j++]=s[i];
            ret[j++]='#';
        }
        ret[j]='\0';
        return ret;
    }
    string manacher(string s)
    {
        int n=s.size();
        int p[n]={0};
        int max_len=0;
        int max_pos;

        int id=0;
        int mx=0;

        for(int i=1;i<s.size();i++)
        {
            if(i<mx)
                p[i]=min(p[2*id-i],mx-i);
            else
                p[i]=1;
            while(s[i-p[i]]==s[i+p[i]])
                p[i]++;
            if(mx<i+p[i])
            {
                id=i;
                mx=i+p[i];
            }
            if(2*(p[i]-1)+1>max_len)
            {
                max_len=2*(p[i]-1)+1;
                max_pos=i-p[i]+1;
            }
        }
        return(s.substr(max_pos,max_len));
    }
    string dealwith(string s)
    {
        int n=s.size();
        string ret(n/2+1,'\0');
        for(int i=0;i<ret.size();i++)ret[i]=s[2*i+1];
        ret[n/2]='\0';
        return ret;
    }
    string longestPalindrome(string s)
    {
        string new_s=convert(s);
        string ret=manacher(new_s);
        ret=dealwith(ret);
        return ret;
    }
};
int main()
{
    Solution solver=Solution();
    string input("babad");
    cout<<solver.longestPalindrome(input)<<endl;
    return 0;
}

