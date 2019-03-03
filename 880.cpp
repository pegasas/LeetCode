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
    string CharToString(char c) {
        string ret;
        ret.push_back(c);
        return ret;
    }

    string decodeAtIndex(string S, int K) {
        long long Size = 0;
        int N = S.length();

        for(int i = 0; i < N; i++) {
            if (isdigit(S[i]))
                Size *= S[i] - '0';
            else
                Size++;
        }

        for(int i = N - 1; i >= 0; i--) {
            K %= Size;
            if (K == 0 && isalpha(S[i]))
                return CharToString(S[i]);

            if (isdigit(S[i]))
                Size /= S[i] - '0';
            else
                Size--;
        }
        return "";
    }
};

//public class Solution {
//public String decodeAtIndex(String S, int K) {
//        long size = 0;
//        int N = S.length();
//
//        for (int i = 0; i < N; ++i) {
//            char c = S.charAt(i);
//            if (Character.isDigit(c))
//                size *= c - '0';
//            else
//                size++;
//        }
//
//        for (int i = N-1; i >= 0; --i) {
//            char c = S.charAt(i);
//            K %= size;
//            if (K == 0 && Character.isLetter(c))
//                return Character.toString(c);
//
//            if (Character.isDigit(c))
//                size /= c - '0';
//            else
//                size--;
//        }
//
//        throw null;
//    }
//}


int main() {
    return 0;
}
