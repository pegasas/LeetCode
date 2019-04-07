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
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return findKthLargest(nums, 0, n - 1, k);
    }
    int findKthLargest(vector<int>& nums, int L, int R, int k) {
        if(L == R) return nums[L];
        int idx = partition(nums, L, R);
        int cnt = idx - L + 1;
        if(cnt == k) return nums[idx];
        return cnt > k ? findKthLargest(nums, L, idx - 1, k) : findKthLargest(nums, idx + 1, R, k - cnt);
    }
    int partition(vector<int>& nums, int L, int R) {
        int val = nums[L];
        int i = L, j = R + 1;
        while(1) {
            while(++i < R && nums[i] >= val);
            while(--j > L && nums[j] < val);
            if(i >= j) break;
            swap(nums[i], nums[j]);
        }
        swap(nums[L], nums[j]);
        return j;
    }
};

//private int findMedium(int[] nums, int L, int R, int k) {
//    if (L >= R) return nums[R];
//    int i = partition(nums, L, R);
//    int cnt = i - L + 1;
//    if (cnt == k) return nums[i];
//    return cnt > k ? findMedium(nums, L, i - 1, k) : findMedium(nums, i + 1, R, k - cnt);
//}
//
//private int partition(int[] nums, int L, int R) {
//    int val = nums[L];
//    int i = L, j = R + 1;
//    while (true) {
//        while (++i < R && nums[i] < val) ;
//        while (--j > L && nums[j] > val) ;
//        if (i >= j) break;
//        swap(nums, i, j);
//    }
//    swap(nums, L, j);
//    return j;
//}
//
//private void swap(int[] nums, int i, int j) {
//    int temp = nums[i];
//    nums[i] = nums[j];
//    nums[j] = temp;
//}
//}

int main() {

}
