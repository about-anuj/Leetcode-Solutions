//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	 vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    
    void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &res){
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                auto p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;
                
                for(int k=0;k<4;k++){
                    int new_x = x+dir[k][0];
                    int new_y = y+dir[k][1];
                    
                    if(new_x>=0 && new_x<grid.size() && new_y>=0 && new_y < grid[0].size()){
                        if(grid[new_x][new_y] == 1){
                            res[i][j] = (abs(i-new_x) + abs(j-new_y));
                            return;
                        }
                        
                        q.push({new_x,new_y});
                    }
                }
            }
        }
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    
	    vector<vector<int>> res(n,vector<int>(m,0));
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j] == 0){
	                bfs(i,j,grid,res);
	            }
	        }
	    }
	    
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends