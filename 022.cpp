#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void backtrade(string sublist, vector<string> &res, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(sublist);
            return;
        }
        if (left > 0) {
            backtrade(sublist + "(", res, left-1, right);
        }
        if (left < right) {
            backtrade(sublist + ")", res, left, right-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrade("", res, n, n);
        return res;
    }
};

int main()
{
    return 0;
}