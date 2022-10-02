class Solution {
public:
    int dp[31][31][1001];
    const int mod=1e9+7;
    int calc(int n,int k,int tgt)
    {
        // if(n==-1) return 0;
        if(tgt<0) return 0;
        if(n==0 and tgt==0) return dp[n][k][tgt]=1;
        if(n==0) return dp[n][k][tgt]=0;
        
        if(dp[n][k][tgt]!=-1) return dp[n][k][tgt];
        // cout<<tgt<<" ";
        long long ways=0;
        for(int i=1;i<=k;i++)
        {
            ways=(ways+calc(n-1,k,tgt-i))%mod;
        }
        return dp[n][k][tgt]=ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return calc(n,k,target);
    }
};