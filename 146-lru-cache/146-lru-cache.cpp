class Node{
    public:
    pair<int,int>data;
    Node* next,*prev;
    
    Node(int key,int value) :data({key,value}) ,next(NULL), prev(NULL){}
};

class LRUCache {

 public:
    
    unordered_map<int,Node*>mp;
    
    Node* front=new Node(0,0),*rear=new Node(0,0);
   
    int cap;
    
    LRUCache(int capacity) {
        cap=capacity;
        front->prev=rear;
        rear->next=front;
    }
    
    
     int get(int key) {
       if(!mp.count(key))
           return -1;
         
         
        Node* dlt=mp[key];
        
        Node* p=dlt->prev;
        Node* f=dlt->next;
        
        p->next=f;
        f->prev=p;
         
       //set the node
        p=front->prev;
        p->next=dlt;
        dlt->prev=p;
        dlt->next=front;
        front->prev=dlt;
         
       //  cout<<front->prev->data.first;
        return dlt->data.second;
    }
    
    
     void put(int key, int value) {
       Node* newnode=new Node(key,value);
         //to handle repeated values
         if(mp.count(key)){
             Node* t=mp[key];
             t->data={key,value};
             Node* dltprev=mp[key]->prev;
             Node* dltnext=mp[key]->next;
             
             dltprev->next=dltnext;
             dltnext->prev=dltprev;
             Node* add=front->prev;
             add->next=mp[key];
             mp[key]->prev=add;
             mp[key]->next=front;
             front->prev=mp[key];
             
             return;
         }
         
         //if size is less then just insert
         if(mp.size()<cap){
             Node* p=front->prev;
             
             p->next=newnode;
             newnode->prev=p;
             newnode->next=front;
             front->prev=newnode;
            
         }
         else
         {
            Node* dlt=rear->next;
            Node* dltnext=dlt->next;
            rear->next=dltnext;
            dltnext->prev=rear;
            mp.erase(dlt->data.first);
            
              Node* p=front->prev;
             
             p->next=newnode;
             newnode->prev=p;
             newnode->next=front;
             front->prev=newnode;
             
         }
         
         mp[key]=newnode;
         //cout<<front->prev->data.first;
        }
    };

 

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */