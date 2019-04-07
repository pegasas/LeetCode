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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
    bool isValidBST(TreeNode* root, int* minV, int* maxV) {
        if(root == NULL) return true;

        if(!isValidBST(root->left, minV, &root->val)) return false;

        if(minV != NULL && (*minV) >= root->val) return false;
        if(maxV != NULL && (*maxV) <= root->val) return false;

        if(!isValidBST(root->right, &root->val, maxV)) return false;
        return true;
    }
};

int main() {

}
