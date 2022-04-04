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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        auto temp=head;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        temp=head;
       // int last=n-k+1,st=k;
        ListNode* fst,*scnd;
        for(int i=0;i<n;i++)
        {
            if(i==k-1)
                fst=temp;
            if(i==n-k)
                scnd=temp;
            
            temp=temp->next;
        }
        swap(fst->val,scnd->val);
        return head;
    }
};