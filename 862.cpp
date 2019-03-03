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

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n=A.size();
        vector<int> sums(n+1,0);
        sums[0]=0;
        for(int i=1;i<=n;i++)sums[i]=sums[i-1]+A[i-1];
        int minWindowSize=n+1;
        deque<int> dq;
        for(int i=0;i<=n;i++)
        {
            while(!dq.empty()&&sums[i]-sums[dq.front()]>=K)
            {
                minWindowSize=min(minWindowSize,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty()&&sums[i]<=sums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        if(minWindowSize==n+1)return -1;
        else return minWindowSize;
    }
};

int main() {
    return 0;
}
