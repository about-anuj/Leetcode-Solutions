class Solution {
public:
    int ans=0,mod=1e9+7;
    vector<vector<vector<int>>>dp;
    long calc(vector<vector<int>>&g,int i,int j,int m,int n,int k,int sum)
    {
        if(i>=m or j>=n) return 0;
        if(i==m-1 and j==n-1 and (sum+g[i][j])%k==0) return 1;
        
        if(dp[i][j][sum%k]!=-1) return dp[i][j][(sum)%k];
        long x=calc(g,i+1,j,m,n,k,sum+g[i][j]);
        long y=calc(g,i,j+1,m,n,k,sum+g[i][j]);
        return dp[i][j][sum%k]=(x+y)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int m=grid.size(),n=grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(k,-1)));
       return calc(grid,0,0,m,n,k,0);
    }
};