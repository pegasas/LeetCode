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
    bool isPrime(int N)
    {
        for(int i=2;i<=int(sqrt(N)+0.5);i++)
            if(N%i==0)return false;
        return true;
    }
    bool isPalindrome(vector<int>& A)
    {
        int len=A.size();
        for(int i=0;i<len/2;i++)
            if(A[i]!=A[len-i-1])return false;
        return true;
    }
    int primePalindrome(int N) {
        if(N<=2)return 2;
        N=(N%2==0?N+1:N);
        for(int i=N;;)
        {
            int k=i;
            vector<int> nums;
            while(k/10!=0)
            {
                nums.push_back(k%10);
                k/=10;
            }
            nums.push_back(k);

            if(nums.size()%2==0&&i!=11)
                i=(int)pow(10,nums.size())+1;
            else
            {
                if(isPalindrome(nums)&&isPrime(i))
                    return i;
                i+=2;
            }
        }
    }
};

class Solution {
public int primePalindrome(int N) {
        if (N <= 2) return 2;
        N = N%2==0 ? N+1 : N;//将N处理为奇数
        for (int i = N;  ; ) {
            int k = i;
            int len = 0;//判断数字的位数
            int[] nums = new int[10];
            while(k / 10 != 0){//将判断的数字处理放入数组中
                nums[len++] = k % 10;
                k /= 10;
            }
            nums[len++] = k;

            if ( len%2 == 0 && i != 11) //判断是否是除11之外的偶数位数字
                i = (int)Math.pow(10,len)+1;//直接跳过偶数位数字
            else {
                if (isHui(i,nums,len)) //是否是回文 即判断一下数组中的数字是否对称
                    if (isprime(i)) return i;//是否是素数
                i+=2;
            }
        }
    }

public static boolean isprime(int i){
        for (int j = 2; j <= Math.sqrt(i); j++)
            if (i % j == 0) return false;
        return true;
    }

public static boolean isHui(int i, int[] nums, int len){
        for (int j = 0; j < len/2; j++)
            if (nums[j] != nums[len-j-1]) return false;
        return true;
    }
}


int main() {
    return 0;
}
