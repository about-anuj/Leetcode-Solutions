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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t=head,*t2;
        t2=t;
        while(t and t->next)
        {
            ListNode* temp=t;
            while(temp and temp->val==t->val)
                temp=temp->next;
          
            t->next=temp;
            t=t->next;
        }
        return t2;
    }
};