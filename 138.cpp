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

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        Node* now = head;
        while(now) {
            Node* copy = new Node(now->val, now->next, NULL);
            now->next = copy;
            now = copy->next;
        }

        for(now = head; now; now = now->next->next) {
            now->next->random = now->random ? now->random->next : NULL;
        }

        Node* new_head = head->next;
        Node* true_now = head;
        Node* copy_now = new_head;
        while(true_now && copy_now) {
            true_now->next = copy_now->next;
            true_now = true_now->next;
            copy_now->next = true_now ? true_now->next : NULL;
            copy_now = copy_now->next;
        }
        return new_head;
    }
};

//class Solution {
//public:
//    Node *copyRandomList(Node *head) {
//        if(head==NULL){
//            return NULL;
//        }
//
//        Node *now = head;         //复制各个节点
//        while(now){
//            Node *copy = new Node(now->val, now->next);
//            now->next = copy;
//            now = copy->next;
//        }
//
//        for(now=head; now; now=now->next->next){        //复制random指针域
//            now->next->random = (now->random)?now->random->next:NULL;
//        }
//
//        Node* h = head->next;     //断开成两个链表
//        Node* t = h;
//        Node* tail = head;
//        for(;;){
//            tail->next = t->next;
//            tail = tail->next;
//            if(tail==NULL){
//                break;
//            }
//            t->next = tail->next;
//            t = t->next;
//        }
//        return h;
//    }
//};

int main() {

}
