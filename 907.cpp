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
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        vector<int> Left(n, -1), Right(n, n);
        stack<int> S;

        while(!S.empty()) S.pop();
        for(int i = 0; i < n; i++) {
            while(!S.empty() && A[S.top()] > A[i]) S.pop();
            if(!S.empty()) Left[i] = S.top();
            S.push(i);
        }

        while(!S.empty()) S.pop();
        for(int i = n -1; i >= 0; i--) {
            while(!S.empty() && A[S.top()] >= A[i]) S.pop();
            if(!S.empty()) Right[i] = S.top();
            S.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (long long)(i - Left[i]) * (Right[i] - i) * A[i];
            ans %= 1000000007;
        }
        return ans;
    }
};

//class Solution {
//public:
//    int sumSubarrayMins(vector<int>& a) {
//        int as=a.size();
//        vector<int> left(as,-1),right(as,as),st;
//        for(int i=0;i<as;i++)//取左边界
//        {
//            while(!st.empty() && a[st.back()]>a[i])
//            {
//                st.pop_back();
//            }
//            if(!st.empty())
//            {
//                left[i]=st.back();
//            }
//            st.emplace_back(i);
//        }
//        st.clear();
//        for(int i=as-1;i>=0;i--)//取右边界
//        {
//            while(!st.empty() && a[st.back()]>=a[i])//相等只计算一次
//            {
//                st.pop_back();
//            }
//            if(!st.empty())
//            {
//                right[i]=st.back();
//            }
//            st.emplace_back(i);
//        }
//        long long rst=0;
//        for(int i=0;i<as;i++)//每个元素的子数组数量累加
//        {
//            rst+=((i-left[i])*(right[i]-i)*a[i]);
//        }
//        return rst%1000000007;
//    }
//};

int main() {
    return 0;
}
