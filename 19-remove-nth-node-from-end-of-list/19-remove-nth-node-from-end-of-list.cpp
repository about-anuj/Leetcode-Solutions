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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur=head,*prev=NULL;
        int k=0;

        while(cur){
            k++;
            cur=cur->next;
        }
        k-=n;
        cur=head;
        while(k--){
            prev=cur;
            cur=cur->next;
        }
        
        //first node
        if(cur==head)
            return head->next;
        
        //else middle or last node
        prev->next=cur->next;
        delete(cur);
         
        return head;
        
    }
};