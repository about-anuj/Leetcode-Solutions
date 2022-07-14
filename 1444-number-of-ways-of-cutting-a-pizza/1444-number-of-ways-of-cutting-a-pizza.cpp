class Solution {
public:
    int memo[55][55];
    int dp[55][55][15];
    int mod=1e9+7;
    int calc(int i,int j,int m,int n,int k)
    {
        
        if(k==0){
            if(memo[i][j]>0)
                return dp[i][j][k]=1;
            return dp[i][j][k]=0;
        }
        
        int ways=0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        
        for(int h=i+1;h<m;h++){
            if(memo[i][j]-memo[h][j]>0 and memo[h][j]>=k)
                ways=(ways+calc(h,j,m,n,k-1))%mod;
        }
        for(int v=j+1;v<n;v++){
            if(memo[i][j]-memo[i][v]>0 and memo[i][v]>=k)
              ways=(ways+calc(i,v,m,n,k-1))%mod;
        }
        
       return dp[i][j][k]=ways;
    }
    int ways(vector<string>& pizza, int k) {
        memset(memo,0,sizeof(memo));
        for(int i=pizza.size()-1;i>=0;i--)
        {
            for(int j=pizza[0].size()-1;j>=0;j--)
            {
                memo[i][j]=memo[i+1][j]+memo[i][j+1]-memo[i+1][j+1]+(pizza[i][j]=='A');
            }
        }
        memset(dp,-1,sizeof(dp));
        return calc(0,0,pizza.size(),pizza[0].size(),k-1);
    }
};


// if (f[r][c][rest] != -1) return f[r][c][rest];
        
//         if (rest == 0) {
//             if (g[r][c] > 0) f[r][c][rest] = 1;
//             else f[r][c][rest] = 0;
//             return f[r][c][rest];
//         }
        
//         f[r][c][rest] = 0;
        
//         // cut horizontally to [row, i-1] [i, n-1]
//         for (int i = r + 1; i < n; i++) {
//             if (g[r][c] - g[i][c] > 0 && g[i][c] >= rest) {
//                 f[r][c][rest] = (f[r][c][rest] + dp(i, c, rest - 1)) % P;
//             }
//         }
        
//         // cut vertically to [col, j-1] [j, m-1]
//         for (int j = c + 1; j < m; j++) {
//             if (g[r][c] - g[r][j] > 0 && g[r][j] >= rest)
//                 f[r][c][rest] = (f[r][c][rest] + dp(r, j, rest - 1)) % P;
//         }
        
//         return f[r][c][rest];