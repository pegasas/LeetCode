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
    bool isvalid(vector<string> &temp, int i, int j){//判断棋盘是否有效
        for (int k = 0; k < i; ++k){//判断列
            if (temp[k][j] == 'Q') return false;
        }
        for (int p = i - 1, q = j - 1; p>=0 && q>=0; --p, --q){//判断左上对角线
            if (temp[p][q] == 'Q') return false;
        }
        for (int p = i - 1, q = j + 1; p >= 0 && q<temp.size(); --p, ++q){//判断右上对角线
            if (temp[p][q] == 'Q') return false;
        }
        return true;
    }


    int dfs(int &count, vector<string> &temp, int i, int n){
        if (i == n)
            return ++count;

        for (int j = 0; j<n; ++j){
            if (isvalid(temp, i, j)) {
                temp[i][j] = 'Q';//递归前修改
                dfs(count, temp, i + 1, n);
            }
            temp[i][j]='.';//递归后恢复
        }
        return count;
    }

    int totalNQueens(int n) {
        int count = 0;
        string aa;
        for (int i = 0; i < n; ++i)
            aa += '.';
        vector<string>temp(n,aa);
        return dfs(count, temp, 0, n);
    }
};

int main() {
    return 0;
}