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
    int n=0;
    ListNode* temp;
    Solution(ListNode* head) {
        temp=head;
        while(head)
        {
           n++;
            head=head->next;
        }
    }
    
    int getRandom() {
       int x=rand()%n;
        ListNode* t=temp;
        while(x)
        {
            x--;
            t=t->next;
        }
        return t->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */