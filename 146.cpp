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

using namespace std;

//使用hash_map和list实现的LRU。 实现了get和put操作
//get 得到对应的value，并且移到队列首。
//put 不存在：队列首加入，此时根据容量可能会挤掉尾元素。存在：移动到队列首。

//改进点在于如果get发生缺页是否需要处理，这时候可以添加一个
//hash_map存储key-value，并在get不到数据时，put一下即可。

class LRUCache {
private:
    int capacity;
    list<pair<int,int>> recent;
    unordered_map<int, list<pair<int,int>>::iterator> pos;
public:
    LRUCache(int capacity) : capacity(capacity) {

    }

    int get(int key) {
        if (pos.find(key) != pos.end()) {
            put(key, pos[key]->second);
            return pos[key]->second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (pos.find(key) != pos.end()) {
            recent.erase(pos[key]);
        } else if (recent.size() >= capacity) {
            pos.erase(recent.back().first);
            recent.pop_back();
        }
        recent.push_front({key, value});
        pos[key] = recent.begin();
    }
};

int main() {
    return 0;
}
