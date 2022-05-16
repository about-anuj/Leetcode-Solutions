class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),ans=0;
        queue<pair<int,int>>q;
        
        q.push({0,0});
        
        while(!q.empty())
        {
            queue<pair<int,int>>q1;
            ans++;
            
            while(!q.empty())
            {
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                
                if(a<n and a>=0 and b<n and b>=0 and grid[a][b]==0)
                {
                    grid[a][b]=1;
                    if(a==n-1 and b==n-1) return ans;
                       
                    for(int i=-1;i<2;i++)
                       for(int j=-1;j<2;j++)
                          if(i!=0 or j!=0)
                            q1.push({a+i,b+j});
                 }
                }
            swap(q,q1);
        }
        return -1;
    }
};