class Solution {
public:
    int dp[1001];
    int solve(vector<int>&c,int i){
        if(i>=c.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        return dp[i]=c[i]+min(solve(c,i+1),solve(c,i+2));
    }
    int minCostClimbingStairs(vector<int>& cost, int i=0) {
        if(i>=cost.size())
            return 0;
        
        memset(dp,-1,sizeof(dp));
        return min(solve(cost,0),solve(cost,1));
    }
};