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
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    int nthMagicalNumber(int N, int A, int B) {
        long long L = 0, R = 2000000000000000000L;
        int G = A / gcd(A, B) * B;
        while (L < R) {
            long long M = L + (R - L) / 2;
            long long tot = M / A + M / B - M / G;
            if (tot < N) L = M + 1;
            else R = M;
        }
        return (int)(L % 1000000007);
    }
};

//class Solution {
//public:
//    int gcd(int a,int b)//求最大公约数
//    {
//        return b==0?a:gcd(b,a%b);
//    }
//
//    int nthMagicalNumber(int N, int A, int B)
//    {
//        long long low=0,high=2000000000000000000L;
//        int g=A*B/gcd(A,B);
//        while(low<high)
//        {
//            long long mid=(low+high)/2;
//            long long t=mid/A+mid/B-mid/g;
//            if(t<N)
//            {
//                low=mid+1;
//            }
//            else
//                high=mid;
//        }
//        return (int)(high%1000000007);
//    }
//};

int main() {
    return 0;
}
