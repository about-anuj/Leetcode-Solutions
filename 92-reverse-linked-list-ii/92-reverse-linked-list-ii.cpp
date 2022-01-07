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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* h1,*newhead,*prev,*nxt=NULL,*curr=head,*h2,*prev_h1; 
        int pos=1;
        //find nodes of right and left position
        while(curr)
        {
         if(pos==left)
         {    
             h1=curr;
             prev_h1=prev;
         }
         if(pos==right)
         {
             break;
         }
         prev=curr;
         curr=curr->next;
         pos++;   
        }
        
        //saparate the list
        
        
        newhead=curr;
        nxt=curr->next;
        
        if(prev_h1)
            prev_h1->next=curr->next;
        curr->next=NULL;
        
        h2=h1;
        reverse(h1);
        
        h2->next=nxt;
        if(prev_h1)
            prev_h1->next=newhead;
        else
            head=newhead;
        
        
        return head;
    }
    private:
    void reverse(ListNode* head)
    {
        ListNode* pre=NULL,*next=NULL;
        while(head)
        {
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
    }
};