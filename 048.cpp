#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int Size = matrix.size();
        for(int i = 0; i < Size; i++) {
            for(int j = i + 1; j < Size; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < Size; i++) {
            for(int j = 0; j < Size / 2; j++) {
                swap(matrix[i][j], matrix[i][Size - 1 - j]);
            }
        }
    }
};

int main()
{
    return 0;
}