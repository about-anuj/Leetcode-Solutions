//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool check(vector<vector<int>>&grid,int sx,int sy,int m,int n)
  {
      return sx>=0 and sx<m and sy>=0 and sy<n and grid[sx][sy]==1;
  }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
        // code here
        queue<pair<int,int>>q;
        int ex=destination.first,ey=destination.second,ans=0,sx=source.first,sy=source.second;
        int m=grid.size(),n=grid[0].size();
        q.push({source.first,source.second});
        int x[]={0,0,1,-1};
        int y[]={1,-1,0,0};
        grid[sx][sy]=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
            int curx=q.front().first,cury=q.front().second;
            q.pop();
            if(curx==ex and cury==ey) return ans;
            
            //charo direction me ghum ja
            for(int i=0;i<4;i++)
            {
                int nx=curx+x[i],ny=cury+y[i];
                // cout<<"ok";
                if(check(grid,nx,ny,m,n))
                {
                    // cout<<curx<<" "<<cury<<endl;
                    grid[nx][ny]=0;
                    q.push({nx,ny});
                }
            }
            
            }
            ans++;
            // cout<<ans;
            // return ans;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends