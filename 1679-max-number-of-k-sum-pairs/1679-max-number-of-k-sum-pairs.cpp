class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
        int ans=0;
        
        for(auto& i:nums) mp[i]++;
        
        for(auto i:mp)
        {
            int n=i.first,c=i.second;
            if(k-n==n) ans+=(c/2);
            
            else if(mp.count(k-n)>0)
            {
                int mn=min(mp[k-n],c);
                ans+=mn;
                mp[k-n]-=mn;
                mp[n]-=mn;
            }
        }
        return ans;
    }
};