class Solution {
public:
    int calc(vector<vector<int>>&grid,int i,int j, int m,int n){
        if(i<0 or j<0 or i>=m or j>=n or grid[i][j]!=1)
             return 0;
        
            grid[i][j]=2;
            int a=calc(grid,i+1,j,m,n);
            int b=calc(grid,i,j+1,m,n);
            int c=calc(grid,i,j-1,m,n);
            int d=calc(grid,i-1,j,m,n);
            return 1+a+b+c+d;
      
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1){
                    ans=max(ans,calc(grid,i,j,m,n));
                }
            }
        }
        return ans;
    }
};