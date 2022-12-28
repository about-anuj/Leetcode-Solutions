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
            
            sm-=(t/2);
            pq.push(t-t/2);
        }
        return sm;
    }
};