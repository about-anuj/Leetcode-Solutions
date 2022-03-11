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
        auto n=1;
        ListNode* temp=head,*prev=NULL;
        while(temp->next) n++,temp=temp->next;
    
        temp->next=head;  //make circular
        //temp=head;
       
        //cout<<n<<" ";
        k%=n;
        k=n-k;
        while(k--)
        {
            temp=temp->next;
        }
        auto ans=temp->next;
        temp->next=NULL;
        return ans;
    }
};