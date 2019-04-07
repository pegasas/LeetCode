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


class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if(minHeap.size() == 0 || num > minHeap.top())
            minHeap.push(num);
        else
            maxHeap.push(num);
        while(maxHeap.size() > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        while(minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        double ans;
        if(minHeap.size() == 0) return 0;
        if(minHeap.size() == maxHeap.size())
            ans = (minHeap.top() + maxHeap.top()) / 2.0;
        else
            ans =  minHeap.top();
        return ans;
    }
};


int main() {

}
