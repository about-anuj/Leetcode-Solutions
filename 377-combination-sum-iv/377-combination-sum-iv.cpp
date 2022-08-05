class Solution {
public:
    int dp[1001];
    int help(vector<int>&nums,int tgt)
    {
        if(tgt==0) return 1;
        if(dp[tgt]!=-1) return dp[tgt];
        
        int way=0;
        for(auto &n:nums)
            if(tgt-n>=0)
                way+=help(nums,tgt-n);
        
        return dp[tgt]=way;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return help(nums,target);
    }
};