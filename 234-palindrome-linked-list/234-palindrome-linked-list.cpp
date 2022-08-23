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
    bool ans=true;
    ListNode* t;
    void calc(ListNode* head)
    {
        if(!head or !ans)
        {
            return;
        }
        
        calc(head->next);
        if(t->val!=head->val)
          ans=false;
        t=t->next;

    }
    bool isPalindrome(ListNode* head) {
        int n=0;
        t=head;
        ListNode*t1=head,*prev;
        while(t) n++,t=t->next;
        if(n==1) return true;
        t=head;
        while(t1 and t1->next) prev=t,t=t->next,t1=t1->next->next;
        if(n%2!=0) t=t->next;
        prev->next=NULL;
        calc(head);
        return ans;
    }
};