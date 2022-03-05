class Solution {
public:
    int solve(unordered_map<int,int>&mp,int idx, vector<int>&dp)
    {
        if(idx>=10001)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
       return dp[idx]=max(solve(mp,idx+2,dp)+mp[idx],solve(mp,idx+1,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums)
            mp[i]+=i;
        
        vector<int>dp(10001,-1);
        return solve(mp,0,dp);
    }
};