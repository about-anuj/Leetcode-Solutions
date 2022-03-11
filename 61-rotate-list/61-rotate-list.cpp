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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        auto n=0;
        ListNode* temp=head,*prev=NULL;
        while(temp) n++,temp=temp->next;
        
        k%=n;
        
        if(k==0) return head;
        
        k=n-k;
        
        
        
        temp=head;
        while(k--)
        {
            prev=temp;
            temp=temp->next;
        }
        
        auto ans=temp;
       if(prev) prev->next=NULL;
        while(temp->next)
            temp=temp->next;
        
        temp->next=head;
        return ans;
    }
};