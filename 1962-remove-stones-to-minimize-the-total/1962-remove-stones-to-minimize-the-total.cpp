class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
     priority_queue<double>pq;
     int sm=0;
        for(auto i:piles)
        {
            pq.push(i);
            sm+=i;
        }
        
        while(k--)
        {
            int t=pq.top();
            pq.pop();
            int f=t;
            if(t%2==0) t/=2;
            else t=t/2+1;
            
            sm-=(f-t);
            pq.push(t);
        }
        return sm;
    }
};