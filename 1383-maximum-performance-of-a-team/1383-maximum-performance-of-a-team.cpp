class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        long ans=0,sum=0,mod=1e9+7;
        vector<vector<int>>cmb;
        for(int i=0;i<n;i++) cmb.push_back({eff[i],speed[i]});
        sort(begin(cmb),end(cmb));
        reverse(begin(cmb),end(cmb));
        
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            sum+=cmb[i][1];
            pq.push(-cmb[i][1]);
            
            if(pq.size()>k)
            {
                sum-=abs(pq.top());
                pq.pop();
            }
            
            // if(pq.size()==k)
            //we have to choose atmost k engineers
                ans=max(ans,(sum*cmb[i][0]));
        }
        return ans%mod;
    }
};