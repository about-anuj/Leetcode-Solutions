class Solution {
public:
    int dp[5003][2];
    int fun(vector<int>&v,int i,int n,int day,int hold)
    {
        if(i>=n) return 0;
        
        if(dp[i][hold]!=-1) return dp[i][hold];
        // cout<<i<<" "<<n<<" "<<day<<" "<<buy<<endl;
        if(hold==0)
            return dp[i][hold]=max(fun(v,i+1,n,i,1)-v[i],fun(v,i+1,n,day,0));
        else
            return dp[i][hold]=max(v[i]+fun(v,i+2,n,i+2,0),fun(v,i+1,n,day,1));
    }
    int maxProfit(vector<int>& prices) {
        // dp.resize(5003,vector<int>(2,-1));
        memset(dp,-1,sizeof(dp));
        return fun(prices,0,prices.size(),0,0);
    }
};