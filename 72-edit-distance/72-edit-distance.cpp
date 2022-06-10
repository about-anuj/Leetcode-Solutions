class Solution {
public:
    int dp[501][501];
//     int calc(string& w1, string& w2, int n, int m)
//     {
//         if(n==-1)
//             return m+1;
//         if(m==-1)
//             return n+1;
        
//         if(dp[n][m]!=-1) return dp[n][m];
        
//         if(w1[n]==w2[m])
//             return dp[n][m]=calc(w1,w2,n-1,m-1);
        
//         return dp[n][m]=1+min({
//             calc(w1,w2,n-1,m),
//             calc(w1,w2,n,m-1),
//             calc(w1,w2,n-1,m-1)
//             });
//     }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
         for (int i = 1; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = j;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }
        return dp[n][m];
    }
};