class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        
        vector<int>dp(10001,0),sum(10001,0);
        for(auto i:nums)
            sum[i]+=i;
        
        dp[0]=0;
        dp[1]=sum[1];
        for(int i=2;i<10001;i++)
            dp[i]=max(dp[i-2]+sum[i],dp[i-1]);
            
        return dp[n-1];
    }
};