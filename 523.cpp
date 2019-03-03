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
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> Map;
        int sum=0;
        Map[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(k) {
                sum %= k;
            }
            if (Map.find(sum) != Map.end()) {
                if (i - Map[sum] > 1) return true;
            }
            else {
                Map[sum] = i;
            }
        }
        return false;
    }
};

//class Solution {
//public:
//    bool checkSubarraySum(vector<int>& nums, int k) {
//        unordered_map<int, int> hash;
//        int sum = 0;
//
//        hash[0] = -1;
//        for(int i=0; i<nums.size(); ++i) {
//            sum += nums[i];
//            if(k) sum %= k;
//            if(hash.find(sum) != hash.end()) {
//                if(i-hash[sum] > 1) return true;
//            }
//            else hash[sum] = i;
//        }
//
//        return false;
//    }
//};

int main() {
    return 0;
}
