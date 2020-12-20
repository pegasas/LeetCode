#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;

        const auto mm = minmax_element(nums.begin(), nums.end());
        const int range = *mm.second - *mm.first;
        const int bin_size = range / n + 1;
        vector<int> min_vals(n, INT_MAX);
        vector<int> max_vals(n, INT_MIN);
        for (const int num : nums) {
            const int index = (num - *mm.first) / bin_size;
            min_vals[index] = min(min_vals[index], num);
            max_vals[index] = max(max_vals[index], num);
        }

        int max_gap = 0;
        int prev_max = max_vals[0];
        for (int i = 1; i < n; ++i) {
            if (min_vals[i] != INT_MAX) {
                max_gap = max(max_gap, min_vals[i] - prev_max);
                prev_max = max_vals[i];
            }
        }
        return max_gap;
    }
};

int main()
{
    return 0;
}
