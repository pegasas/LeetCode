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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *list1,*list2;
        list2=list1=head;
        while(n--)list2=list2->next;
        if(list2==NULL)return head->next;
        while(list2->next!=NULL)
        {
            list1=list1->next;
            list2=list2->next;
        }
        list1->next=list1->next->next;
        return head;
    }
};
int main()
{
    return 0;
}
