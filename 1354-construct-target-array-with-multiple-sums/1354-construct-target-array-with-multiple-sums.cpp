
class Solution {
public:
    bool isPossible(vector<int>& target) {
        long total=accumulate(begin(target),end(target),(long)0);
       priority_queue<long int>pq;
        
        for(auto i:target)
            pq.push((long)i);
        
        while(pq.top()!=1){
            int top=pq.top();
            pq.pop();
            
            total-=top; 
            if(total>=top or total<=0)
                return false;
            
           // cout<<leftsum<<" ";
            
            top%=total;
           // pq.pop();
            total+=top;
            pq.push(top>0?top:total);
           
        }
    return true;
    }
};