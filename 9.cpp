#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x<0)return false;
        int len=1;
        while(x/len>=10)len*=10;
        while(x)
        {
            int left=x/len;
            int right=x%10;
            if(left!=right)return false;
            else
            {
                x=(x%len)/10;
                len/=100;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
