#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    bool differ_one(string &s, string &t) {
        int n = 0;
        for (int i = 0; i < s.size(); ++i)
            if ((n += s[i] != t[i]) > 1) return false;
        return n == 1;
    }
    vector<vector<int>> fa;//fa[1]有元素x，代表wordList[1]由wordList[x]转化过来
    vector<string> tmp;
    vector<vector<string>> ans;
    void dfs(int index, vector<string>& wordList) {
        if (fa[index].empty()) {
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            reverse(tmp.begin(), tmp.end());
        }
        for (auto &x : fa[index]) {
            tmp.push_back(wordList[x]);
            dfs(x, wordList);
            tmp.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        int b = -1, e = -1, x;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == beginWord) b = i;
            if (wordList[i] == endWord) e = i;
        }
        if (e == -1) return ans;
        if (b == -1) wordList.push_back(beginWord), b = wordList.size() - 1;
        queue<int> que;
        fa.assign(wordList.size(), vector<int>());
        vector<int> index(wordList.size(), 0);//index代表第几层
        que.push(b), index[b] = 1;//b是端点
        while (!que.empty()) {
            x = que.front(), que.pop();
            if (index[e] && index[x] >= index[e]) break;
            for (int i = 0; i < wordList.size(); ++i)
                if ((index[i] == 0 || index[x] + 1 == index[i]) && differ_one(wordList[x], wordList[i]))
                    if (index[i] == 0) index[i] = index[x] + 1, que.push(i), fa[i].push_back(x);
                    else fa[i].push_back(x);
        }
        if (index[e] == 0) return ans;
        tmp.push_back(endWord);
        dfs(e, wordList);
        tmp.pop_back();
        return ans;
    }

};


int main() {
    return 0;
}