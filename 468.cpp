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

using namespace std;

class Solution {
public:
    void split(const string& src, const string& delim, vector<string>& results){
        string str = src;
        int st = 0, ind;
        string substr;
        ind = str.find_first_of(delim, st);
        while(ind != string::npos){
            substr = str.substr(st, ind - st);
            results.push_back(substr);
            st = ind + 1;
            if(st == string::npos){
                results.push_back("");
                return;
            }
            ind= str.find_first_of(delim, st);
        }
        substr = str.substr(st, str.length() - st);
        results.push_back(substr);

    }
    string checkIPv4(const string& IP){
        vector<string>results;
        split(IP, ".", results);
        if(results.size() != 4)return "Neither";
        for(int i = 0; i < 4; i++){
            string str = results[i];
            if(str.length() == 0 || str.length() > 3)return "Neither";
            if(str.length() > 1 && str[0] == '0')return "Neither";
            int ind = 0;
            while(ind < str.length()){
                if(str[ind] < '0' || str[ind] > '9')return "Neither";
                ind++;
            }
            int dec = atoi(str.c_str());
            if(dec > 255 || dec < 0)return "Neither";
        }
        return "IPv4";
    }
    string checkIPv6(const string& IP){
        vector<string>results;
        split(IP, ":", results);
        //cout << results.size() << endl;
        if(results.size() != 8)return "Neither";
        for(int i = 0; i < 8; i++){
            string str = results[i];
            if(str.length() == 0 || str.length() > 4)return "Neither";
            int ind = 0;
            while(ind < str.length()){
                char c = str[ind];
                if(c >= '0' && c <= '9' || c >= 'A' && c <= 'F' || c >= 'a' && c <= 'f'){
                    ind++;
                    continue;
                }
                return "Neither";
            }
        }
        return "IPv6";
    }
    string validIPAddress(string IP) {
        vector<string>results;
        int ind = IP.find_first_of(".", 0);
        if(ind != string::npos)return checkIPv4(IP);
        ind = IP.find_first_of(":", 0);
        if(ind != string::npos)return checkIPv6(IP);
        return "Neither";

    }
};

int main() {
    return 0;
}
