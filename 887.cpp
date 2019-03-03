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

//题意:
//你有K个鸡蛋，在一栋N层高的建筑上，被要求测试鸡蛋最少在哪一层正好被摔坏。
//你只能用没摔坏的鸡蛋测试。如果一个鸡蛋在上一次测试中没有被摔坏，那么你可以重复使用，否则，你只能用下一个鸡蛋。
//需要求，最小的步数，使得你在这么多步内一定测试出结果。

//O(K * N^2)
//首先，这个题比较绕。需要求一个最优决策使得步数最小，但是实际的步数是随着真实结果变化而变化的。
//于是，为了保证在我们假设的步数内一定能够解完，我们可以假设每次决策都会得到最坏结果。
//
//dp[n][k] 表示用k个鸡蛋测n层最少需要多少步。
//我们可以枚举第一次在第i层扔鸡蛋，会得到两种结果:
//
//鸡蛋坏掉: 我们接下来需要面对的情形是: 用 k-1 个鸡蛋来测量 i-1 层，所以最少需要 dp[i-1][k-1] 步。
//鸡蛋没坏: 我们接下来要面对的情形是: 用 k 个鸡蛋来测量 n-i 层，所以最少需要 dp[n-i][k] 步。
//因为我们总会面对最坏情况，所以，在第i层扔，会用 max(dp[i-1][k-1], dp[n-i][k]) + 1 步。
//所以我们的递推式如下:
//dp[n][k] = min{ max(dp[i-1][k-1], dp[n-i][k]) + 1 } (1 <= i <= n)
//
//思路: O(K * logN)
//我们可以改变一下求解的思路，求k个鸡蛋在m步内可以测出多少层：
//假设: dp[k][m] 表示k个鸡蛋在m步内最多能测出的层数。
//那么，问题可以转化为当 k <= K 时，找一个最小的m，使得dp[k][m] <= N。
//
//我们来考虑下求解dp[k][m]的策略：
//假设我们有k个鸡蛋第m步时，在第X层扔鸡蛋。这时候，会有两种结果，鸡蛋碎了，或者没碎。
//如果鸡蛋没碎，我们接下来会在更高的楼层扔，最多能确定 X + dp[k][m-1] 层的结果；
//如果鸡蛋碎了，我们接下来会在更低的楼层扔，最多能确定 Y + dp[k-1][m-1] 层的结果 (假设在第X层上还有Y层)。
//因此，这次扔鸡蛋，我们最多能测出 dp[k-1][m-1] (摔碎时能确定的层数) + dp[k][m-1] (没摔碎时能确定的层数) + 1 (本层) 层的结果。
//另外，我们知道一个鸡蛋一次只能测一层，没有鸡蛋一层都不能测出来。
//因此我们可以列出完整的递推式:
//dp[k][0] = 0
//dp[1][m] = m (m > 0)
//dp[k][m] = dp[k-1][m-1] + dp[k][m-1] + 1 (k > 0, m>0)

class Solution {
public:
    int superEggDrop(int K, int N) {
        int dp[N+2][K+2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 1; i <= N; i++) {
            dp[i][0] = 0;
            for(int j = 1; j <= K; j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + 1;
                if (dp[i][j] >= N) {
                    return i;
                }
            }
        }
        return N;
    }
};

//class Solution {
//public:
//    // NOTE: 第一维和第二维换了下位置
//    int superEggDrop(int K, int N) {
//        int dp[N+2][K+2];
//        memset(dp, 0, sizeof(dp));
//        dp[0][0] = 0;
//        for (int m = 1; m <= N; m++) {
//            dp[m][0] = 0;
//            for (int k = 1; k <= K; k++) {
//                dp[m][k] = dp[m-1][k] + dp[m-1][k-1] + 1;
//                if (dp[m][k] >= N) {
//                    return m;
//                }
//            }
//        }
//        return N;
//    }
//};

int main() {
    return 0;
}
