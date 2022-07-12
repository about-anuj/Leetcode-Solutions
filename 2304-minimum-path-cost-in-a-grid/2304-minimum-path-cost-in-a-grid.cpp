class Solution {
public:
    //int dp[10001][10001];
    int calc(vector<vector<int>>&gr,vector<vector<int>>&cost,int i, int j, int m, int n,vector<vector<int>>&dp){
        if(i==m-1) return gr[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=INT_MAX;
        for(int k=0;k<n;k++)
        ans= min(ans,gr[i][j]+cost[gr[i][j]][k]+calc(gr,cost,i+1,k,m,n,dp));
    
     return dp[i][j]=ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
         int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        ans= min(calc(grid,moveCost,0,i,m,n,dp),ans);
        
        return ans;
    }
};