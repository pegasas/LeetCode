#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0,j=0;
        int match=0;
        int pre_match=-1;
        while(i<s.length())
        {
            if(j<p.length()&&(s[i]==p[j]||p[j]=='?')){i++;j++;}
            else if(j<p.length()&&p[j]=='*')
            {
                pre_match=j;
                match=i;
                j++;
            }
            else if(pre_match!=-1)
            {
                j=pre_match+1;
                i=match+1;
                match++;
            } else
                return false;
        }
        while(j<p.length()&&p[j]=='*')j++;
        return j==p.length();

    }
};

int main() {
    return 0;
}