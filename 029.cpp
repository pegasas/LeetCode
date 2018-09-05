#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        //因为带符号整数的范围为-2^n~2^n-1，故存在一种特殊情况

        //取两数的绝对值
        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;//注意此处异或的作用
        if (n == 1) return sign == 1 ? m : -m;

        while (m >= n) {
            long long t = n, p = 1;
            while (m >= (t << 1)) {
                p <<= 1;
                t <<= 1;
            }
            res += p;
            m -= t;
        }

        return sign > 0 ? res : -res;



    }
};


int main()
{
    Solution s;
    cout<<s.strStr("", "")<<endl;
    return 0;
}