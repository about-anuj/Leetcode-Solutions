class Solution {
public:
    int ans=INT_MAX;
    int dp[101][101][101];
    int calc(int i, int n, vector<vector<int>>& costs, int cur,int a, int b)
    {
        if(i==n){
          return cur;
        }
        
        if(dp[a][b][i]!=-1) return dp[a][b][i];
     
        if(a==n/2)
        {
            for(int j=i;j<n;j++)
                cur+=costs[j][1];
            
            return cur;
        }
        
        if(b==n/2)
        {
            for(int j=i;j<n;j++)
               cur+=costs[j][0];
            
            return cur;
        }
        
      return  dp[a][b][i]=min(calc(i+1,n,costs,cur,a+1,b)+costs[i][0],
                              calc(i+1,n,costs,cur,a,b+1)+costs[i][1]);
        
       
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(dp,-1,sizeof(dp));
        return calc(0,costs.size(),costs,0,0,0);
     //  return  ans;
    }
};