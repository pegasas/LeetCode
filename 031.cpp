#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>&nums) {
        int len = nums.size();
        int k = -1, l = 0, i = 0;//注意三个变量的初始化值

        for (i = len - 2/*即倒数第二个元素(逆序遍历)*/;i >= 0;--i)
            if (nums[i + 1] > nums[i]) {
                k = i;
                break;//因为是逆序,故此时得到的k一定是最大的
            }

        if (k == -1) {
            reverse(nums.begin(), nums.end());//此时代表原数组为逆序排列,故直接反转
            return;
        }

        //接下来找i
        for (i = len - 1;i >= 0;--i) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }

        //二者交换
        swap(nums[k], nums[l]);

        //再反转k之后的元素(不包括nums[k])
        reverse(nums.begin() + k + 1, nums.end());

    }
};



int main()
{
    Solution s;
    cout<<s.strStr("", "")<<endl;
    return 0;
}