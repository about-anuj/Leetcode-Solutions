class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
     int m=grid.size(),n=grid[0].size(),c=0;
      
        k%=(m*n);
        
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cur=(n*i)+j;
                
                int newpos=(cur+k)%(m*n);
                int r=newpos/n;
                int c=newpos%n;
                ans[r][c]=grid[i][j];
            }
        }
        return ans;
    }
};