class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
     int m=grid.size(),n=grid[0].size(),c=0;
       deque<int>dq;
        for(auto i:grid)
            for(auto j:i)
                dq.push_back(j);
        
        k%=(m*n);
        while(k--)
        {
            int b=dq.back();
            dq.pop_back();
            dq.push_front(b);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j]=dq.front();
                dq.pop_front();
            }
        }
        return grid;
    }
};