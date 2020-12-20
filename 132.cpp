#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  int minCut(string s) {
    const int n = s.length();
    // dp[i] = min cuts of s[0~i]
    vector<int> dp(n, n);
    for (int start = 0; start < n; start++)
      for (int d = 0; d <= 1; ++d) // ö��������ż�����Ĵ�
        for (int i = start, j = start + d; i >= 0 && j < n && s[i] == s[j]; --i, ++j) // ÿ��ö�ٻ��Ĵ������û��Ĵ�s[i:j]������ͨ��dp[i]����dp[j]
          dp[j] = min(dp[j], (i ? (dp[i - 1] + 1) : 0));
    return dp[n - 1];
  }
};

int main()
{

}
