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
    bool isvalid(vector<string>& cur,int i,int j)
    {
        for(int k=0;k<i;k++)
            if(cur[k][j]=='Q')
                return false;
        for(int p=i-1,q=j-1;p>=0&&q>=0;p--,q--)
            if(cur[p][q]=='Q')
                return false;
        for(int p=i-1,q=j+1;p>=0&&q<cur.size();p--,q++)
            if(cur[p][q]=='Q')
                return false;
        return true;
    }
    void dfs(vector<vector<string>>& ret,vector<string> &cur,int i,int n)
    {
        if(i==n)
        {
            ret.push_back(cur);
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(isvalid(cur,i,j))
            {
                cur[i][j]='Q';
                dfs(ret,cur,i+1,n);
                cur[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        string line;
        for(int i=0;i<n;i++)line+='.';
        vector<string> cur(n,line);
        dfs(ret,cur,0,n);
        return ret;
    }
};

int main() {
    return 0;
}