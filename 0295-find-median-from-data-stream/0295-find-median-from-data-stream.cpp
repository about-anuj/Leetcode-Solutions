class MedianFinder {
public:
    priority_queue<int>mx;
    priority_queue<int,vector<int>,greater<int>> mn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // cout<<num;
        if(mx.size() and num<=mx.top()) mx.push(num);
        else mn.push(num);
        
        if(abs((int)mn.size()-(int)mx.size())>1)
        {
            if(mn.size()>mx.size())
            {
                mx.push(mn.top());
                mn.pop();
            }
            else
            {
                mn.push(mx.top());
                mx.pop();
            }
        }
        // cout<<mn.size()<<" "<<mx.size()<<endl;
    }
    
    double findMedian() {
        int n=mn.size(),m=mx.size();
        // cout<<m+n<<" ";
        if(m==n) return (double)(mn.top()+mx.top())/2;
        // cout<<"ok";
        return m>n?mx.top():mn.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */