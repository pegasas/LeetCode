#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int>::iterator iter = nums.begin();
        vector<int>::iterator iter_end = nums.end();
        long long int threeSumValue = 0;
        long long int temp = 0;
        long long int threeSumGap = INT_MIN;
        threeSumGap *=  - 1;
        while (iter != iter_end) {
            temp = *iter + twoSum(nums, target - *iter, iter - nums.begin());
            if (abs(temp - target) < threeSumGap) {
                threeSumGap = abs(temp - target);
                threeSumValue = temp;
            }

            iter++;
        }

        return threeSumValue;
    }


    int twoSum(vector<int> numsCopy, int target, int pos) {
        numsCopy.erase(numsCopy.begin() + pos);
        sort(numsCopy.begin(), numsCopy.end());

        //copy(numsCopy.begin(), numsCopy.end(), ostream_iterator<int>(cout, "\n"));
        vector<int>::iterator iter = numsCopy.begin();
        vector<int>::iterator iter_end = numsCopy.end();
        vector<int>::iterator left = iter;
        long long  int gap = INT_MIN;
        gap *= -1;
        long long  int temp = 0;
        iter_end--;
        vector<int>::iterator right = iter_end;
        while (iter != iter_end) {

            temp = *iter + *iter_end - target;
            if (temp<0) {
                if (abs(temp)<gap) {
                    left = iter;
                    right = iter_end;
                    gap = abs(temp);
                }
                ++iter;
            }
            else if (temp>0) {
                if (abs(temp)<gap) {
                    left = iter;
                    right = iter_end;
                    gap = abs(temp);
                }
                iter_end--;
            }
            else {

                left = iter;
                right = iter_end;
                gap = 0;

                break;
            }
        }

        return *left + *right;
    }


};

int main()
{
    return 0;
}