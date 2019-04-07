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
#include <climits>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstring>
using namespace std;

class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> child;
        string word;
        TrieNode(): child(vector<TrieNode*>(26, NULL)), word(""){}
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if(board.size() == 0 || board[0].size() == 0) return ans;

        TrieNode* root = buildTrie(words);
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& board, int x, int y, TrieNode *node, vector<string> &ans) {
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return;

        char c = board[x][y];
        int idx = c - 'a';
        if(c == '#' || node->child[idx] == NULL) {
            return;
        }

        node = node->child[idx];
        board[x][y] = '#';
        if(node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        dfs(board, x + 1, y, node, ans);
        dfs(board, x - 1, y, node, ans);
        dfs(board, x, y + 1, node, ans);
        dfs(board, x, y - 1, node, ans);

        board[x][y] = c;
    }
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for(int i = 0; i < words.size(); i++) {
            TrieNode* node = root;
            for(int j = 0; j < words[i].length(); j++) {
                int idx = words[i][j] - 'a';
                if(node->child[idx] == NULL) {
                    node->child[idx] = new TrieNode();
                }
                node = node->child[idx];
            }
            node->word = words[i];
        }
        return root;
    }
};


int main() {

}
