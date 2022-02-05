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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //if list size is 0 
       if(lists.size()==0) return NULL;
        
        //to store elements in priority order
       priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<lists.size();i++)
        {
            //store the head of thee list and traverse it
            ListNode* t=lists[i];
            while(t)
            {
                pq.push((t->val));
                t=t->next;
            }
        }
        //if queue is not empty
        //one case is [[]] i.e. there is a node but theat is null

        if(pq.size()>0){
        ListNode* head=new ListNode((pq.top()));
        pq.pop();
        ListNode* t=head;
        while(!pq.empty())
        {
            t->next=new ListNode((pq.top()));
            pq.pop();
            t=t->next;
        }
        return head;
        }
        else
            return NULL;
    }
};