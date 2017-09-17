#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry=0;
        ListNode* head=NULL;
        ListNode* now=NULL;
        while(l1||l2||carry)
        {
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            if(head==NULL){now=new ListNode(sum%10);head=now;}
            else {now->next=new ListNode(sum%10);now=now->next;}
            carry=sum/10;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }
        return head;
    }
};
int main()
{
    return 0;
}
