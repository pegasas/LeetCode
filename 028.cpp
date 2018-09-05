#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> getFail(string P) {
        vector<int> next(P.size()+1);
        next[0]=next[1]=0;
        for(int i=1;i<P.size();i++) {
            int j=next[i];
            while(j && P[i]!=P[j])j=next[j];
            next[i+1]=(P[i]==P[j]?j+1:0);
        }
        return next;
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        vector<int> next = getFail(needle);
        int j=0;
        for(int i=0;i<haystack.size();i++) {
            while(j && haystack[i] != needle[j])j=next[j];
            if(haystack[i]==needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout<<s.strStr("", "")<<endl;
    return 0;
}