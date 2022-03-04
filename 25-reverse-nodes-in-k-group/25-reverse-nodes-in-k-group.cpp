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
 
    void reverse(ListNode* head){
        ListNode* pre=NULL,*next=NULL;
        while(head)
        {
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* t=head;
        vector<pair<ListNode*,ListNode*>>v;
       // v.push_back({NULL,NULL});
        while(t){
            int j=k;
            ListNode* st=t,*end;
            while(t and j--){
                end=t;
                t=t->next;
            }
            end->next=NULL;
            
          if(!t and j) end=NULL;
            
         v.push_back({st,end});
        }
        
        
        //if size of list is less than k
         if(v[0].second==NULL)
         {
             reverse(v[0].first);
             return v[0].second;
         }
        
    
        reverse(v[0].first);
        swap(v[0].first,v[0].second); //as list became reverse so swap first and last node
        
        for(int i=1;i<v.size();i++)
        {
            // it means it is last node and its length is less then k
            if(v[i].second==NULL){
                v[i-1].second->next=v[i].first;
                break;
            }
            
            reverse(v[i].first);
            swap(v[i].first,v[i].second);
            //cout<<v[i-1].second->val<<" "<<v[i].first->val<<endl;
            v[i-1].second->next=v[i].first;
            
        }
        // for(auto i:v)
        // {
        //     ListNode* t=i.first;
        //    while(t)
        //    {
        //        cout<<t->val<<" ";
        //        t=t->next;
        //    }
        //     cout<<endl;
        // }
        return v[0].first;
    }
};