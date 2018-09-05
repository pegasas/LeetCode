#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len == 0)
            return "";
        string str = "";
        bool flag = true;
        for(int i=0;;i++){
            char temp;
            if(i>=strs[0].length())
                break;
            else
                temp = strs[0][i];
            for(int j=1;j<len;j++){
                if(i>=strs[j].length()){
                    flag = false;
                    break;
                }
                if(strs[j][i]==temp)
                    continue;
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                str += temp;
                continue;
            }
            else{
                break;
            }
        }
        return str;
    }
};

int main()
{
    return 0;
}