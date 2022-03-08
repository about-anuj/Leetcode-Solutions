class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>>q;
        int m=grid.size(),n=grid[0].size(),ans=0;
        int nbr[]={0,1,0,-1,0};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
              if(grid[i][j]=='1')
              {
                  grid[i][j]='0';
                  q.push({i,j});
                  ans++;
                  while(!q.empty())
                  {
                      pair<int,int>p=q.front();
                      q.pop();
                  for(int k=0;k<4;k++)
                  {
                    int x=p.first+nbr[k],y=p.second+nbr[k+1];
                    if(x>=0 and x<m and y>=0 and y<n and grid[x][y]=='1'){
                        grid[x][y]='0';
                        q.push({x,y});
                    }
                  }
                  }
              }
            }
        }
        return ans;
    }
};

// for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == '1') {
//                    islands++;
//                    grid[i][j] = '0';
//                    queue<pair<int, int>> todo;
//                    todo.push({i, j});
//                      while (!todo.empty()) {
//                        pair<int, int> p = todo.front();
//                        todo.pop();
//                        for (int k = 0; k < 4; k++) {
//                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
//                             if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
//                                 grid[r][c] = '0';
//                                 todo.push({r, c});
//                             }
//                         }
//                     }
//                 }
//             }
//         }