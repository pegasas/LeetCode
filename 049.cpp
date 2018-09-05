#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int Size = strs.size();
        map<string, vector<string>> Map;
        for(int i = 0; i < Size; i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            Map[tmp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(map<string, vector<string>>::iterator iter1 = Map.begin(); iter1 != Map.end(); iter1++) {
            vector<string> items = iter1 -> second;
            sort(items.begin(), items.end());
            res.push_back(items);
        }
        return res;
    }
};

int main()
{
    return 0;
}