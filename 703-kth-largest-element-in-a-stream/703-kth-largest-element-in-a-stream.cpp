class KthLargest {
public:
    priority_queue<int>pq;
    int c;
    KthLargest(int k, vector<int>& nums) {
        c=k;
        for(auto i:nums)
        {
            pq.push(-1*i);
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(-1*val);
        if(pq.size()>c) pq.pop();
      return -1*pq.top();    
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */