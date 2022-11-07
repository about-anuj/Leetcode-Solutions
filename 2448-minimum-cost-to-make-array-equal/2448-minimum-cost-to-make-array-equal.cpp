class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
       vector<pair<int,int>>v;
        long long n=nums.size(),mn=1e18;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],cost[i]});
        }
        sort(begin(v),end(v));
        vector<long long>pre(n),suf(n);
        long long costsum=0,combined=0;
        for(int i=0;i<n;i++)
        {
            long long ni=v[i].first,ci=v[i].second;
            combined+=ni*ci;
            costsum+=ci;
            pre[i]=ni*costsum-combined;
        }
        
        costsum=0,combined=0;
        for(int i=n-1;i>=0;i--)
        {
            long long ni=v[i].first,ci=v[i].second;
            combined+=ni*ci;
            costsum+=ci; 
            suf[i]=combined-ni*costsum;
        }
        
        for(int i=0;i<n;i++)
        {
          mn=min({mn,pre[i]+suf[i]});    
        }
        return mn;
    }
};