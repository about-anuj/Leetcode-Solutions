/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head,*nxt;
        //insert all copies one by one
        while(temp)
        {
            nxt=temp->next;
            Node* t=new Node(temp->val);
            t->next=nxt;
            temp->next=t;
            temp=nxt;
        }
        
        Node* prev=head;
        while(prev)
        {
            if(prev->random==NULL)
                prev->next->random=NULL;
            else
            {
                prev->next->random=prev->random->next;
            }
            prev=prev->next->next;
          // if(prev) temp->next=prev->next;
        }
        prev=head;
        Node* idle=new Node(0);
        Node* copy,*copyitr=idle;
        while(prev)
        {
          nxt=prev->next->next;
          copy=prev->next;
          copyitr->next=copy;
          copyitr=copy;
            
          prev->next=nxt;     //restore original list
          prev=nxt;
        }
        return idle->next;
    }
};