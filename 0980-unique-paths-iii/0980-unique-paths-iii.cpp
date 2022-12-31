class Solution {
public:
    int ans=0,count=1;
    void calc(int st_i, int  st_j,int m, int n, vector<vector<int>>& grid, int empty)
    {
        if(st_i<0 or st_i>=m or st_j<0  or st_j>=n or grid[st_i][st_j]==-1)
            return ;
        
        if(grid[st_i][st_j]==2)
        {
           // cout<<"ok";
            if(empty==count)
            ans++;
            
            return;
        }
       grid[st_i][st_j]=-1;
        
         calc(st_i+1,st_j,m,n,grid,empty+1) ;                                                  calc(st_i,st_j+1,m,n,grid,empty+1);
         calc(st_i-1,st_j,m,n,grid,empty+1);
         calc(st_i,st_j-1,m,n,grid,empty+1);
        
        grid[st_i][st_j]=0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int st_i,st_j,end_i,end_j;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    st_i=i;
                    st_j=j;
                }
               
                else if(grid[i][j]==0)
                    count++;
            }
        }
       // cout<<count<<" ";
       // cout<<st_i<<st_j<<end_i<<end_j;
    //    vector<vector<int>>dp(m,vector<int>(n,-1));
      calc(st_i,st_j,m,n,grid,0);
       return ans;
    }
};