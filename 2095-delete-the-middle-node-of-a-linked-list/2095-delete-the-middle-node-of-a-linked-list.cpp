/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        int n=0;
        ListNode* t=head,*prev;
        while(t)
        {
            n++;
            t=t->next;
        }
        n/=2;
        //cout<<n;
        ListNode* temp=head;
        while(n>0)
        {
            prev=temp;
            temp=temp->next;
            --n;
        }
        if(temp->next==NULL) prev->next=NULL;
        
       if(prev and temp){ prev->next=temp->next;
        
               }
        return head;
    }
};