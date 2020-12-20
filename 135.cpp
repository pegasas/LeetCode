#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  int candy(vector<int>& ratings) {
    const int n = ratings.size();
    vector<int> ans(n, 1);
    for (int i = 1; i < n; ++i)
      if (ratings[i] > ratings[i - 1]) ans[i] = ans[i - 1] + 1;
    for (int i = n - 2; i >= 0; --i)
      if (ratings[i] > ratings[i + 1]) ans[i] = max(ans[i], ans[i + 1] + 1);
    return accumulate(begin(ans), end(ans), 0);
  }
};

int main()
{
    return 0;
}
