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

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long t=numerator,d=denominator;
        map<long long,int> Map;
        string ans;

        if(t*d<0)ans="-";

        t=abs(t),d=abs(d);
        ans+=to_string(t/d);
        t%=d;
        if(!t)return ans;

        ans+='.';
        while(t)
        {
            if(Map.count(t)){
                ans.insert(Map[t],"(");
                ans.push_back(')');
                return ans;
            }
            Map[t]=ans.size();
            ans+='0'+t*10/d;
            t=t*10%d;
        }
        return ans;
    }
};

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long t = numerator, d = denominator;
        map<long long, int> A;
        string ans;
        if (t * d < 0) ans = "-";
        t = abs(t), d = abs(d);
        ans += to_string(t / d);
        t %= d;
        if (!t) return ans;
        ans += '.';
        while (t) {
            if (A.count(t)) {
                ans.insert(A[t], "("), ans.push_back(')');
                return ans;
            }
            A[t] = ans.size(), ans += '0' + t * 10 / d;
            t = t * 10 % d;
        }
        return ans;
    }
};

int main() {
    return 0;
}
