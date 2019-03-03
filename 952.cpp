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
private:
    int N = 100000;
    vector<int> primes;
    bool sieve[100005];
    int fa[100005];
public:
    void getPrimes() {
        memset(sieve, 0, sizeof(sieve));
        primes.clear();
        for (int i = 2; i < N; i++) {
            if (!sieve[i]) primes.push_back(i);
            for(int j=0; j < primes.size() && primes[j] * i <= N; j++) {
                sieve[primes[j] * i] = true;
                if(i % primes[j] == 0) break;
            }
        }
    }
    int getfather(int x) {
        return fa[x] == x ? x : fa[x] = getfather(fa[x]);
    }
    void merge(int x, int y) {
        int fx = getfather(x), fy = getfather(y);
        fa[fy] = fx;
    }
    int largestComponentSize(vector<int>& A) {
        for(int i = 0; i <= N; i++) fa[i] = i;
        getPrimes();
        for(int i = 0; i < A.size(); i++) {
            for(int d = 2; d * d <= A[i]; d++) {
                if (A[i] % d == 0) {
                    if (!sieve[d]) {
                        merge(A[i], d);
                    }
                    if (!sieve[A[i] / d]) {
                        merge(A[i], A[i] / d);
                    }
                }
            }
        }
        map<int,int> Map;
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            int faA = getfather(A[i]);
            Map[faA]++;
            if (Map[faA] > ans) ans = Map[faA];
        }
        return ans;
    }
};

int main() {
    return 0;
}
