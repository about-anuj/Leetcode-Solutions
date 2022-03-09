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
        if(!head or !head->next) return head;
        
        auto temp=head,prev=new ListNode(0);
        auto th=prev;
        while(temp)
        {
            if(temp->next and temp->val==temp->next->val){
               
                auto cur=temp->val;
                while(temp and temp->val==cur)
                    temp=temp->next;
                
                prev->next=temp;
                
            }
            else{
            prev->next=temp;
            prev=prev->next;
            temp=temp->next;
            }
        }
        prev->next=NULL;
        return th->next;
    }
};