#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string shortestPalindrome(string s) {
    const string r(s.rbegin(), s.rend());
    const int n = s.size();
    for (int i = 0; i < n; ++i)
      if (s.compare(0, n - i, r, i, n - i) == 0)
        return r.substr(0, i) + s;
    return "";
  }
};

int main()
{
    return 0;
}
