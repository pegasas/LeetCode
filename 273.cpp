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

using namespace std;

class Solution {
public:
    const int Mod[3] = { 1000000000,1000000,1000 };
    string H[3] = { "Billion","Million","Thousand" },
            M[8] = { "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" },
            L[20] = { "Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
                      "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
    void update(string &ans) {
        ans += ans == "" ? "" : " ";
    }
    string numberToWords2(int num) {//num小于1000
        if (num < 20)
            return L[num];//zero的情况
        string ans;
        if (num >= 100)
            ans += L[num / 100] + " Hundred",num%=100;//num变两位数
        if (num == 0)
            return ans;
        else if (num < 20)
            update(ans),ans += L[num];
        else {
            update(ans), ans += M[num / 10 - 2], num %= 10;//num变一位数
            if (num == 0)
                return ans;
            else
                update(ans), ans+= L[num];
        }
        return ans;
    }
    string numberToWords(int num) {
        if (num < 20) //zero的情况
            return L[num];
        string ans;
        for(int i = 0; i < 3; ++i)
            if (num >= Mod[i])
                update(ans),ans += numberToWords2(num / Mod[i]) + " " + H[i], num %= Mod[i];
        if(num)
            update(ans), ans += numberToWords2(num);
        return ans;
    }
};

int main() {
    return 0;
}
