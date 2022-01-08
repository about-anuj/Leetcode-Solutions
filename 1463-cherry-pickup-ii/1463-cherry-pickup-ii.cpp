class Solution {
public:
    int dp[71][71][71];
    int calc(vector<vector<int>>&g, int r, int c1,int c2,int n, int m)
    {
        if(r<0 or r>=n or c1<0 or c1>=m or c2<0 or c2>=m) return 0;
        
        int mx=0;
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int new_c1=c1+i;
                int new_c2=c2+j;
                mx=max(mx,calc(g,r+1,new_c1,new_c2,n,m));
            }
        }
        int curcherry=0;
        if(c1==c2)
            curcherry=g[r][c1];
        else
            curcherry=g[r][c1]+g[r][c2];
        
        dp[r][c1][c2]=curcherry+mx;
        return curcherry+mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
        return calc(grid,0,0,m-1,n,m);
    }
};