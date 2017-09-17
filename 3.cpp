#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int Map[256];
        memset(Map,0,sizeof(Map));
		int ans=0;
		int j=0;
		for(int i=0;i<s.length();i++)
		{
			if(Map[s[i]]==0)
				Map[s[i]]=1;
			else
			{
				ans = max(ans,(int)(i-j));
				while(s[j]!=s[i])
				{
					Map[s[j]]=0;
					j++;
				}
				j++;
			}
		}
		ans=max(ans,(int)(s.length()-j));
		return ans;
    }
};

int main()
{
    return 0;
}
