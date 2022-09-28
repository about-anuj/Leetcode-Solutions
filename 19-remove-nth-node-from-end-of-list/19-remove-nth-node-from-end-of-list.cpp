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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode* temp=head,*dummy=new ListNode(0);
        dummy->next=head;
        temp=dummy;
        int n=0;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        
        temp=dummy;
        int step=n-k;
        while(--step>0) temp=temp->next;
        
        ListNode* nx=NULL,*tgt=temp->next;
        if(temp->next) nx=temp->next->next;
        temp->next=nx;
        delete(tgt);
        return dummy->next;
        
    }
};