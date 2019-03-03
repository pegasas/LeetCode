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
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int max = INT_MIN;
public:
    int solve(TreeNode* root){
        if(!root)
            return 0;
        int val = root->val;
        int tmp = val;

        int lMax = solve(root->left);
        int rMax = solve(root->right);

        if(lMax>0)
            val+=lMax;
        if(rMax>0)
            val+=rMax;

        if(val>max)
            max = val;

        int res = tmp;
        res = res>(tmp+lMax)?res:tmp+lMax;
        res = res>(tmp+rMax)?res:tmp+rMax;

        return res;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return max;
    }
};


int main() {
    return 0;
}