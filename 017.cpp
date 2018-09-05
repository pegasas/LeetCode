#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string str[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		vector<string> table(str,str+10);
		vector<string> ret;
		letterCombinations(ret,digits,"",0,table);
		return ret;
    }
    void letterCombinations(vector<string> &ret,
                            string digits,
                            string cur,
                            int index,
                            vector<string> table)
    {
        if(index==digits.length())
        {
            if(cur.length()!=0)ret.push_back(cur);
            return;
        }
        string tmp=table[digits[index]-'0'];
        for(int i=0;i<tmp.length();i++)
        {
            string next=cur+tmp[i];
            letterCombinations(ret,digits,next,index+1,table);
        }
    }
};
int main()
{
    return 0;
}
