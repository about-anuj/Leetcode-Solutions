class Solution {
public:
    int dp[2000001];
    int calc(vector<int>&nums,int tgt)
    {
        if(tgt==0) return 1;
        if(dp[tgt]!=-1) return dp[tgt];
        
        dp[tgt]=0;
        for(auto i:nums)
            if(tgt-i>=0)
                dp[tgt]+=calc(nums,tgt-i);
        
        return dp[tgt];
    }
    int combinationSum4(vector<int>& nums, int target) {
       memset(dp,-1,sizeof(dp));
            return calc(nums,target);
    }
};