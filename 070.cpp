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
#define LL long long

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int n_1 = 1;
        int n_2 = 0;
        int tmp;
        for(int i=1; i<=n; i++){
            tmp = n_1+n_2;
            n_2 = n_1;
            n_1 = tmp;
        }
        return tmp;
    }
};



int main() {
    return 0;
}
