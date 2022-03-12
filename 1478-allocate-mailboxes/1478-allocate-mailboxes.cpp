class Solution {
public:
    int cost[101][101],dp[101][101];
    
    int ok(vector<int>& houses, int n, int k, int i)
    {
        if(k==0 and i==n) return 0;
        if(k==0 or i==n) return 1e6;
        
        if(dp[k][i]!=-1)
            return dp[k][i];
        
        int ans=1e6;
       for(int j=i;j<n;j++){
          ans=min(ans,cost[i][j]+ok(houses,n,k-1,j+1)); 
       }
        dp[k][i]=ans;
        return ans;
    }
    int minDistance(vector<int>& houses, int k) {
         int n=houses.size();
        sort(begin(houses),end(houses));
        memset(dp,-1,sizeof(dp));
        memset(cost,0,sizeof(cost));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int median=houses[(i+j)/2];
                for(int m=i;m<=j;m++)
                {
                    cost[i][j]+=abs(median-houses[m]);
                }
            }
        }
        return ok(houses,n,k,0);
    }
};
 
 //    int dp(vector<int>& houses, int n, int k, int i) {
 //        if (k == 0 && i == n) return 0;
 //        if (k == 0 || i == n) return INF;
 //        if (memo[k][i] != -1) return memo[k][i];
 //        int ans = INF;
 //        for (int j = i; j < n; j++)
 //            ans = min(ans, costs[i][j] + dp(houses, n, k-1, j + 1));
 //        return memo[k][i] = ans;
 //    }