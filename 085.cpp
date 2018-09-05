#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector <vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m,0);
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j]=0;
                }
            }
            ret = max(ret, lineMaximalRectangle(heights));
        }
        return ret;
    }
    int lineMaximalRectangle(vector<int> heights) {
        if (heights.size() == 0) {
            return 0;
        }
        stack<int> s;
        int ret = 0;
        int i = 0;
        heights.push_back(0);//处理到结尾结束的那一次统计
        while (i < heights.size()) {
            if (s.empty() || heights[i] > heights[s.top()]) {
                s.push(i);
                i++;
            } else {
                int u = s.top();
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                ret = max(ret, heights[u] * width);
            }
        }
        return ret;
    }
};


int main() {
    return 0;
}