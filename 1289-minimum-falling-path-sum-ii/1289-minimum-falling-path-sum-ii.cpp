class Solution {
public:
    int dp[202][202];
    int calc(vector<vector<int>>&g,int i,int j,int m,int n)
    {
        if(i<0 or j<0 or i>=m or j>=n) return 0;
        if(i==m-1) return g[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int res=INT_MAX;
        for(int k=0;k<n;k++)
        {
            if(k!=j)
            {
                res=min(res,g[i][j]+calc(g,i+1,k,m,n));
            }
        }
        return dp[i][j]=res;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<grid[0].size();i++)
            ans=min(ans,calc(grid,0,i,grid.size(),grid[0].size()));
        return ans;
    }
};