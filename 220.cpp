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

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> record;
        for(int i=0;i<nums.size();i++){
            if(record.lower_bound((long long)nums[i]-(long long)t)!=record.end()&&
            *record.lower_bound((long long)nums[i]-(long long)t)<=(long long)nums[i]+(long long)t)
                return true;
            record.insert(nums[i]);
            if(record.size()>k)record.erase(nums[i-k]);
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> record;
        for(int i = 0; i < nums.size(); i++){
            if(record.lower_bound((long long)nums[i] - (long long)t)  != record.end()
               && (long long)*record.lower_bound((long long)nums[i] - (long long)t) <= (long long)nums[i] + (long long)t)
                return true;

            record.insert(nums[i]);
            if(record.size() > k)
                record.erase(nums[i - k]);
        }
        return false;
    }
};


int main() {
    return 0;
}
