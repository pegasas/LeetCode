#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>The_Stack;
        int i=0;
        The_Stack.push('#');
        while(i<s.size()) {
            if((s[i]==')'&&The_Stack.top()=='(')||(s[i]==']'&&The_Stack.top()=='[')||(s[i]=='}'&&The_Stack.top()=='{')) {
                i++;
                The_Stack.pop();
            }
            else  {
                The_Stack.push(s[i]);
                i++;
            }
        }
        if(The_Stack.top()=='#')
            return true;
        return false;
    }
};

int main()
{
    return 0;
}