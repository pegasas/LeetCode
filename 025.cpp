#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getListSize(ListNode* head)
    {
        int len=0;
        while(head)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* insertHead(ListNode *head,ListNode *node)
    {
        node->next=head;
        return node;
    }
    ListNode* reverseKGroup(ListNode* head,int k)
    {
        int len=getListSize(head);
        ListNode tmpHead(-1);
        ListNode *pNode=&tmpHead;
        while(len>=k)
        {
            ListNode *fakeHead=NULL;
            for(int i=0;i<k;i++)
            {
                ListNode *tmpNode=head;
                head=head->next;
                tmpNode->next=NULL;
                fakeHead=insertHead(fakeHead,tmpNode);
            }
            pNode->next=fakeHead;
            while(pNode->next)pNode=pNode->next;
            len-=k;
        }
        pNode->next=head;
        return tmpHead.next;
    }
};

int main()
{
    return 0;
}
