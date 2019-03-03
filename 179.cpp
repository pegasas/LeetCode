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

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> strnums;
        for(int i = 0; i < n; i++) {
            strnums.push_back(to_string(nums[i]));
        }
        sort(strnums.begin(), strnums.end(), cmp);
        string res = "";
        for(int i = 0; i < n; i++) {
            res += strnums[i];
        }
        if (res[0] == '0') return "0";
        return res;
    }
    static bool cmp(string a, string b) {
        string str1 = a + b;
        string str2 = b + a;
        return str1 > str2;
    }
};

//class Solution {
//public:
//    string largestNumber(vector<int>& nums) {
//        int n=nums.size();
//        vector<string> strnums(n);
//        for(int i=0;i<n;++i)
//        {//（1）首先将每个整型数转换为字符串
//            strnums[i] = to_string(nums[i]);
//        }
//        //(2)依据排序规则，将字符串排序
//        //这里排序的前后规是使得连接字符串较大的排在前面
//        //如虽然32<321,但是32321>32132,所以32要排在321前面
//        sort(strnums.begin(), strnums.end(), cmp);
//        string res = "";
//        for(int i=0;i<n;++i)
//        {//(3)将排序后的各字符串连接成一个大字符串
//            res += strnums[i];
//        }
//        if(res[0]=='0') return "0";//防止输入[0,0]时res="00"等情况
//        return res;
//
//    }
//    static bool cmp(string strnum1, string strnum2)
//    {//利用ab>ba,则a排在b前面
//        string str1 = strnum1+strnum2;
//        string str2 = strnum2+strnum1;
//        return str1>str2;//找最大数，则大元素(按自定义规则而言)排在前面
//    }
//};


int main() {
    return 0;
}
