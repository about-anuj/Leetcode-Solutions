class Solution {
public:
    int calc(int m,int n, vector<vector<int>>&dp, vector<vector<int>>&g)
    {
        if(m<0 or n<0) return INT_MAX;
       else if(m==0 and n==0) return g[m][n];
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        return dp[m][n]=g[m][n]+min(calc(m-1,n,dp,g),calc(m,n-1,dp,g));
    }
    int minPathSum(vector<vector<int>>& grid) {
       int n=grid[0].size();
       int m=grid.size();
       vector<vector<int>>dp(m,vector<int>(n,-1));
        return calc(m-1,n-1,dp,grid);
    }
};

// int minCost(vector<vector<int>> &cost,int m, int n,vector<vector<int>>& memo) { 
//       if (n <0 || m <0) 
//          return INT_MAX; 
//       else if(m==0 && n==0) 
//          return cost[m][n]; 
//       if(memo[m][n]!=-1)
//           return memo[m][n];
//       int r=cost[m][n]+min(minCost(cost,m-1,n,memo),minCost(cost,m,n-1,memo));
//         memo[m][n]=r;
//       return r;
//     } 
    
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size(),n=grid[0].size();
//         vector<vector<int>> memo(m,vector<int>(n, -1));
//         return minCost(grid,m-1,n-1,memo);
//     }

// int minCost(vector<vector<int>> &cost,int m, int n,vector<vector<int>>& memo) { 
//       if (n <0 || m <0) 
//          return INT_MAX; 
//       else if(m==0 && n==0) 
//          return cost[m][n]; 
//       if(memo[m][n]!=-1)
//           return memo[m][n];
//       int r=cost[m][n]+min(minCost(cost,m-1,n,memo),minCost(cost,m,n-1,memo));
//         memo[m][n]=r;
//       return r;
//     } 
    
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size(),n=grid[0].size();
//         vector<vector<int>> memo(m,vector<int>(n, -1));
//         return minCost(grid,m-1,n-1,memo);
//     }