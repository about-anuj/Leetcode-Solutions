class MyCircularQueue {
public:
    int sz;
    vector<int>q;
    int st=0,end=0;
    MyCircularQueue(int k) {
        sz=k;
        q.resize(k,-1);
    }
    
    bool enQueue(int value) {
        if(q[st]==-1 and q[end]==-1){
            q[st]=value;
            return true;
        }
        if(q[(end+1)%sz]!=-1) return false;
        
        end=(end+1)%sz;
        q[end]=value;
        return true;
    }
    
    bool deQueue() {
        if(q[st]==-1) return false;
        q[st]=-1;
        
        if(q[(st+1)%sz]!=-1)
        st=(st+1)%sz;
        
        return true;
    }
    
    int Front() {
        return q[st]!=-1?q[st]:-1;
    }
    
    int Rear() {
       
        return q[end]!=-1?q[end]:-1;
    }
    
    bool isEmpty() {
       return st==end and q[st]==-1;
    }
    
    bool isFull() {
        return (end+1)%sz==st;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */