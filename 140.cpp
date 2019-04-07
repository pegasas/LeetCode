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
    map<int, vector<string>> Map;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(int i = 0; i < wordDict.size(); i++)
            dict.insert(wordDict[i]);
        Map.clear();
        return dfs(s, 0, dict);
    }
    vector<string> dfs(string &s, int start, unordered_set<string> dict) {
        if(Map.find(start) != Map.end()) return Map[start];

        if(start == s.length()) {
            Map[start] = vector<string>(1, string());
            return Map[start];
        }

        vector<string> ret;
        for(int i = start; i < s.length(); i++) {
            string now = s.substr(start, i - start + 1);
            if(dict.find(now) != dict.end()) {
                vector<string> suffixes = dfs(s, i + 1, dict);
                for(int j = 0; j < suffixes.size(); j++) {
                    ret.push_back(now + (suffixes[j] == "" ? "" : " ") + suffixes[j]);
                }
            }
        }
        Map[start] = ret;
        return ret;
    }
};

//class Solution {
//public:
//    vector<string> wordBreak(string s, vector<string>& wordDict) {
//        unordered_set<string> dict;
//        for(string str : wordDict)
//            dict.insert(str);
//
//        vector<string >ret =
//
//        return ret;
//    }
//
//    vector<string> dfs(string &s, int start, unordered_set<string> &dict){
//        if(memo.find(start) != memo.end())
//            return memo[start];
//
//        if(start == s.length()){
//            memo[start] = vector<string>(1, string());
//            return memo[start];
//        }
//
//        vector<string> ret;
//        for(int i = start; i < s.length(); i++){
//            string ss = s.substr(start, i - start + 1);
//            if(dict.find(ss) != dict.end()){
//                vector<string> suffixes = dfs(s, i + 1, dict);
//
//                for(string suffix : suffixes)
//                    ret.push_back(ss + (suffix == "" ? "" : " ") + suffix);
//            }
//        }
//
//        memo[start] = ret;
//        return ret;
//    }
//
//private:
//    map<int, vector<string> > memo;
//};


int main() {

}
