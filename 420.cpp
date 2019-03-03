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

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string s) {
        int n = s.length();
        vector<int> c;
        bool lowercase = false, uppercase = false, digit = false;
        for(int i=0; i<n; i++){
            if('0'<=s[i] && s[i] <='9') digit = true;
            if('a'<=s[i] && s[i] <= 'z') lowercase = true;
            if('A'<=s[i] && s[i] <= 'Z') uppercase = true;
            int j = i;
            while (i<n && s[j]==s[i+1]) {
                i++;
            }
            c.push_back(i-j+1);
        }
        int add = (digit? 0:1) + (lowercase? 0:1) + (uppercase?0:1);
        int ans = 0;
        if(n<6){
            ans = 6-n;
            if(add>ans) ans += add-ans;
        }
        else{
            int haveto_delete = (n>20? n-20:0);
            ans += haveto_delete;
            int m = c.size();
            for(int i=0; i<m; i++){
                if(c[i]>=3){
                    if(c[i]%3==0 && haveto_delete>0){
                        haveto_delete -= 1;
                        c[i] -= 1;
                    }
                    else{
                        if(c[i]%3==1 && haveto_delete>1){
                            haveto_delete -= 2;
                            c[i] -= 2;
                        }
                    }
                }
            }
            int change_cnt = 0;
            for(int i=0; i<m; i++){
                if(c[i]>=3&&haveto_delete>0){
                    int needto_delete = c[i] -2;
                    if(needto_delete <= haveto_delete){
                        haveto_delete -= needto_delete;
                        c[i] = 2;
                    }
                    else{
                        c[i] -= haveto_delete;
                        haveto_delete = 0;
                    }
                }
                change_cnt += c[i]/3;
            }
            ans += max(change_cnt, add);
        }
        return ans;
    }
};

int main() {
    return 0;
}
