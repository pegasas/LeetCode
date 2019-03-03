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

using namespace std;

struct POS
{
    int x;
    int y;
    POS(int newx, int newy): x(newx), y(newy) {}
};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(board[i][j] == 'O')
                {
                    if(i == 0 || i == m-1 || j == 0 || j == n-1)
                    {// remain 'O' on the boundry
                        bfs(board, i, j, m, n);
                    }
                }
            }
        }
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
    void bfs(vector<vector<char>> &board, int i, int j, int m, int n)
    {
        queue<POS*> q;
        board[i][j] = '*';
        POS* pos = new POS(i, j);
        q.push(pos);
        while(!q.empty())
        {
            POS* front = q.front();
            q.pop();
            if(front->x > 0 && board[front->x-1][front->y] == 'O')
            {
                POS* up = new POS(front->x-1, front->y);
                q.push(up);
                board[up->x][up->y] = '*';
            }
            if(front->x < m-1 && board[front->x+1][front->y] == 'O')
            {
                POS* down = new POS(front->x+1, front->y);
                q.push(down);
                board[down->x][down->y] = '*';
            }
            if(front->y > 0 && board[front->x][front->y-1] == 'O')
            {
                POS* left = new POS(front->x, front->y-1);
                q.push(left);
                board[left->x][left->y] = '*';
            }
            if(front->y < n-1 && board[front->x][front->y+1] == 'O')
            {
                POS* right = new POS(front->x, front->y+1);
                q.push(right);
                board[right->x][right->y] = '*';
            }
        }
    }
};

int main() {
    return 0;
}
