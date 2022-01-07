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
        if(left==right) return head;
         right-=left;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        head=dummy;
        //find nodes of right and left position
        while(--left)
        {
          head=head->next;
        }
        
        ListNode* start=head->next;
        while(right--)
        {
            ListNode* nxt=start->next;
            start->next=nxt->next;
            nxt->next=head->next;
            head->next=nxt;
        }
        
        
        return dummy->next;
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