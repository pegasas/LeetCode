//用有限状态机，非常简洁，不需要复杂的各种判断！
//
//先枚举一下各种合法的输入情况：
//
//1.空格+ 数字 +空格
//
//2.空格+ 点 + 数字 +空格
//
//3.空格+ 符号 + 数字 +　空格
//
//4.空格 + 符号 + 点 +　数字　＋空格
//
//5.空格 + (1, 2, 3, 4） + e +　(1, 2, 3, 4) +空格
//
//        组后合法的字符可以是：
//
//1.数字
//
//2.空格
//
//有限状态机的状态转移过程：
//
//起始为0：
//
//　　当输入空格时，状态仍为0，
//
//　　输入为符号时，状态转为3，3的转换和0是一样的，除了不能再接受符号，故在0的状态的基础上，把接受符号置为-1；
//
//　　当输入为数字时，状态转为1, 状态1的转换在于无法再接受符号，可以接受空格，数字，点，指数；状态1为合法的结束状态；
//
//　　当输入为点时，状态转为2，状态2必须再接受数字，接受其他均为非法；
//
//　　当输入为指数时，非法；
//
//状态1：
//
//　　接受数字时仍转为状态1，
//
//　　接受点时，转为状态4，可以接受空格，数字，指数，状态4为合法的结束状态，
//
//　　接受指数时，转为状态5，可以接受符号，数字，不能再接受点，因为指数必须为整数，而且必须再接受数字；
//
//状态2：
//
//　　接受数字转为状态4；
//
//状态3：
//
//　　和0一样，只是不能接受符号；
//
//状态4：
//
//　　接受空格，合法接受；
//
//　　接受数字，仍为状态4；
//
//　　接受指数，转为状态5，
//
//状态5：
//
//　　接受符号，转为状态6，状态6和状态5一样，只是不能再接受符号，
//
//　　接受数字，转为状态7，状态7只能接受空格或数字；状态7为合法的结束状态；
//
//状态6：
//
//　　只能接受数字，转为状态7；
//
//状态7：
//
//　　接受空格，转为状态8，状态7为合法的结束状态；
//
//　　接受数字，仍为状态7；
//
//状态8：
//
//　　接受空格，转为状态8，状态8为合法的结束状态；

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        //输入参数枚举
        enum InputType{
            INVALID, //代表不正确
            SPACE, // 代表空格
            SIGN, // 代表符号
            DIGIT,
            DOT, //代表点符号
            EXPONENT, //代表科学计算
            NUM_INPUTS //数字输入
        };

        int transitionTable[][NUM_INPUTS] =
                {
                        -1, 0, 3, 1, 2, -1,     // next states for state 0
                        -1, 8, -1, 1, 4, 5,     // next states for state 1
                        -1, -1, -1, 4, -1, -1,     // next states for state 2
                        -1, -1, -1, 1, 2, -1,     // next states for state 3
                        -1, 8, -1, 4, -1, 5,     // next states for state 4
                        -1, -1, 6, 7, -1, -1,     // next states for state 5
                        -1, -1, -1, 7, -1, -1,     // next states for state 6
                        -1, 8, -1, 7, -1, -1,     // next states for state 7
                        -1, 8, -1, -1, -1, -1,     // next states for state 8
                };


        int state = 0, i = 0;
        while (s[i] != '\0')
        {
            InputType inputType = INVALID;
            if (isspace(s[i]))
                inputType = SPACE;
            else if (s[i] == '+' || s[i] == '-')
                inputType = SIGN;
            else if (isdigit(s[i]))
                inputType = DIGIT;
            else if (s[i] == '.')
                inputType = DOT;
            else if (s[i] == 'e' || s[i] == 'E')
                inputType = EXPONENT;

            state = transitionTable[state][inputType];

            if (state == -1)
                return false;
            else
                i++;
        }

        return state == 1 || state == 4 || state == 7 || state == 8;

    }
};

int main() {
    return 0;
}