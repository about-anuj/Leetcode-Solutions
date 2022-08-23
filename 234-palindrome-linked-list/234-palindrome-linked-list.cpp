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
    //TC O(n)
    //SC O(1) ASC O(n/2)=O(n)
    bool ans=true;
    ListNode* t;
    void reverse(ListNode* head)
    {
       ListNode* t1=NULL,*nxt=NULL;
        while(head)
        {
            nxt=head->next;
            head->next=t1;
            t1=head;
            head=nxt;
        }
    }
    bool isPalindrome(ListNode* head) {
        int n=0;
        t=head;
        ListNode*t1=head,*prev;
        while(t) n++,t=t->next;
        if(n==1) return true;
        t=head;
        //find mid
        while(t1 and t1->next) prev=t,t=t->next,t1=t1->next->next;
        //if n is odd then skip mid character
        if(n%2!=0) t=t->next;
        //saparate the list
        prev->next=NULL;
        reverse(head);
        while(t){
            cout<<t->val<<" ";
            if(t->val!=prev->val) return false;
            t=t->next;
            prev=prev->next;
        }
        return true;
    }
};