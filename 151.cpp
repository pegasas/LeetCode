#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#define LL long long

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if(s.length()==0)return;
        reverse(s.begin(),s.end());
        int flag=0;
        string::iterator it=s.begin(),pre=s.begin();
        while((*it)==' '&&it!=s.end())s.erase(it); //remove all blanks before
        while(it!=s.end())
        {
            if((*it)==' '&&flag==1)
            {
                s.erase(it);
                continue;
            }
            else if((*it)==' '&&flag==0)
            {
                flag=1;
                reverse(pre,it);
            }
            else if(flag==1)
            {
                pre=it;
                flag=0;
            }
            it++;
        }
        if(flag==0)reverse(pre,it);
        else s.erase(s.end()-1);
    }
};

int main() {
    return 0;
}
