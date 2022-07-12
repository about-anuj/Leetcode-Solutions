class Solution {
public:
    int dp[101][101];
    int calc(vector<vector<int>>&gr,vector<vector<int>>&cost,int i, int j, int m, int n){
        if(i==m-1) return gr[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=0;k<n;k++)
        ans= min(ans,gr[i][j]+cost[gr[i][j]][k]+calc(gr,cost,i+1,k,m,n));
    
     return dp[i][j]=ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
     int m=grid.size(),n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        ans= min(calc(grid,moveCost,0,i,m,n),ans);
        
        return ans;
    }
};