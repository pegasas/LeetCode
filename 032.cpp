#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> parenthesesStack;
        int maxLength=0;
        int lastValidIndex=0;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '(') {
                parenthesesStack.push(i);
            } else {
                if (parenthesesStack.empty()) {
                    lastValidIndex = i+1;
                } else {
                    parenthesesStack.pop();
                    if (parenthesesStack.empty()) {
                        maxLength = max(maxLength, i-lastValidIndex+1);
                    } else {
                        maxLength = max(maxLength, i-parenthesesStack.top());
                    }
                }

            }
        }
        return maxLength;
    }
};

int main()
{
    return 0;
}