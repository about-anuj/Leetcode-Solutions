class Solution {
public:
    bool isvalid(vector<vector<int>>&g,int i,int j,int n)
    {
        if(i<n and i>=0 and j<n and j>=0 and g[i][j]==0) return 1;
        return 0;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),ans=0;
        //vector<vector<int>>temp=grid;
        queue<pair<int,int>>q;
        if(grid[0][0]==1 or grid[n-1][n-1]==1) return -1;
        
        q.push({0,0});
        
        while(!q.empty())
        {
            int sz=q.size();
            ans++;
            while(sz--)
            {
                //direction
              //  {1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}
                int x[]={1,1,0,0,-1,-1,1,-1};
                int y[]={1,0,1,-1,0,-1,-1,1};
                
                int a=q.front().first;
                int b=q.front().second;
                if(a==n-1 and b==n-1) return ans;
                q.pop();
                
                for(int j=0;j<8;j++)
                {
                    int nx=a+x[j];
                    int ny=b+y[j];
                
              //      cout<<a<<" "<<b<<endl;
               // if(a==n-1 and b==n-1) return ans+2;
                   
                    if(isvalid(grid,nx,ny,n) and grid[nx][ny]==0)
                    {
                    grid[nx][ny]=1;
                    q.push({nx,ny});
                    }
               
                }
                
                
            }
            
          //  ans++;
        }
        return -1;
    }
};