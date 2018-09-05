#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string strs[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int lenValues = sizeof(values) / sizeof(values[0]);
        string ret = "";
        for(int i=0;i<lenValues;i++) {
            while(num>=values[i])
            {
                num-=values[i];
                ret+=strs[i];
            }
        }
        return ret;
    }
};

int main()
{
    return 0;
}