class Solution {
public:
    //vector<vector<int>>vis;
    void dfs(int i,int j,vector<vector<char>>&grid)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='0' )
            return;
        
        //vis[i][j]=1;
        grid[i][j]='0';
        dfs(i,j+1,grid);
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
      //  vis.resize(grid.size(),vector<int>(grid[0].size(),-1));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};