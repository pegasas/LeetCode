#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* now = head;
        ListNode* next = head->next;

        while(now != NULL && next != NULL) {
            swap(now->val, next->val);
            if (next->next == NULL) {
                break;
            }
            now = next->next;
            next = next->next->next;
        }
        return head;
    }
};

int main()
{
    return 0;
}