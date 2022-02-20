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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* t=head;
        ListNode* ans=new ListNode(0);
        ListNode* x=ans;
        vector<int>v;
        while(t)
        {
            if(t->val==0)
            {
                t=t->next;
                continue;
            }
            int c=0;
            while(t and t->val!=0){
                c+=t->val;
            t=t->next;
            }
             ListNode* newnode=new ListNode(c);
             ans->next=newnode;
            
            ans=newnode;
        }
      
        return x->next;
    }
};