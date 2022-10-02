class Solution {
public:
    int dp[31][1001];
    const int mod=1e9+7;
    int calc(int n,int k,int tgt)
    {
        if(tgt<0) return 0;
        if(n==0 or tgt==0) return dp[n][tgt]=(n==tgt);
        
        if(dp[n][tgt]!=-1) return dp[n][tgt];
     
        long long ways=0;
        for(int i=1;i<=k;i++)
        {
            ways=(ways+calc(n-1,k,tgt-i))%mod;
        }
        return dp[n][tgt]=ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return calc(n,k,target);
    }
};