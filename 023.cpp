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
    class cmp
    {
    public:
        bool operator() (const ListNode *a, const ListNode *b)
        {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(int i=0;i<lists.size();i++)
            if(lists[i])pq.push(lists[i]);
        if(pq.empty())return (ListNode*)NULL;
        ListNode* head=pq.top();pq.pop();
        ListNode* tail=head;
        if(tail->next)pq.push(tail->next);
        while(!pq.empty())
        {
            tail->next=pq.top();
            tail=tail->next;
            pq.pop();
            if(tail->next)pq.push(tail->next);
        }
        return head;
    }
};

int main()
{
    return 0;
}
