class Solution {
public:
    vector<vector<int>>dp;
    int calc(vector<int>&p,int n,int day,int t)
    {
        if(day==n or t==0) return 0;
        
        if(dp[day][t]!=-1) return dp[day][t];
        
        int a1=calc(p,n,day+1,t);
        int buy=t%2==0,ans2;
        if(buy)
           ans2=calc(p,n,day+1,t-1)-p[day];
        else
            ans2=calc(p,n,day+1,t-1)+p[day];
        
        return dp[day][t]=max(a1,ans2);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),res=0;
        dp.resize(prices.size(),vector<int>(5,-1));
        return calc(prices,n,0,4);
    }
};