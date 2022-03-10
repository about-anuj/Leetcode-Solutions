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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy=new ListNode(0);
        auto t=dummy;
        int carry=0;
        while(l1 or l2){
            int val=carry;
            //if l1 is not null then add that node value
            if(l1)
            {
                val+=l1->val;
                l1=l1->next;
            }
            //similarly as l1
            if(l2){
                val+=l2->val;
                l2=l2->next;
            }
           
            //calculation for carry
            carry=val/10;
            val=val%10;
            
            //make node and link
            auto cur=new ListNode(val);
            t->next=cur;
            t=cur;
            
            //if both become null and carry exist that means we have
            //to add carry value so add that and this will be our last value
            if(!l1 and !l2 and carry>0){
               auto cur=new ListNode(carry);
               t->next=cur;  
                
            }
        }
        
        return dummy->next;
    }
};