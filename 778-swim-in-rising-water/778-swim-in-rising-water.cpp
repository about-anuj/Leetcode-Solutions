class Solution {
public:
    
    bool is_valid(int i,int j,int n)
    {
        if(i<0 or i>=n or j<0 or j>=n) return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        //dist,i,j
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
  
        pq.push({grid[0][0],0,0});
        grid[0][0]*=-1;
        while(!pq.empty())
        {
           vector<int>v=pq.top();
            pq.pop();
            int d=v[0];
            int x=v[1];
            int y=v[2];
            
            if(x==n-1 and y==n-1) return d;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(is_valid(nx,ny,n) and grid[nx][ny]>=0)
                {
                    pq.push({max(d,grid[nx][ny]),nx,ny});
                    grid[nx][ny]*=-1;
                }
            }
        }
        return 0;
    }
};