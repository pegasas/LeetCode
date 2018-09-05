#include<bits/stdc++.h>
#define INTMAX (int)0x7fffffff
#define INTMIN (int)0x80000000
using namespace std;
class Solution
{
public:
    int myAtoi(string str)
    {
        if(str=="")return 0;
        int i=0;
        long long res=0;
        while(str[i]&&str[i]==' ')i++;
        int flag=1;
        if(str[i]=='-'){flag=-1;i++;}
        else if(str[i]=='+')i++;
        while(str[i])
            if(str[i]>='0'&&str[i]<='9')
            {
                res=res*10+str[i]-'0';
                if(res>INT_MAX)
                {
                    if(flag==1)return INT_MAX;
                    else return INT_MIN;
                }
                i++;
            }
            else break;
        res*=flag;
        return (int)res;
    }
};
int main()
{
    return 0;
}
