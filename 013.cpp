#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> Dic = { { 'I' , 1 }, { 'V' , 5 }, { 'X' , 10 }, { 'L' , 50 }, { 'C' , 100 }, { 'D' , 500 }, { 'M' , 1000 } };
        int sum = Dic[s.back()];
        for(int i = s.length() - 2; i >= 0; --i){
            sum +=  (Dic[s[i]] < Dic[s[i+1]] ? -Dic[s[i]] : Dic[s[i]]);
        }
        return sum;
    }
};

int main()
{
    return 0;
}