class Solution {
public:
    int dp[501][501];
    int calc(string& w1, string& w2, int n, int m)
    {
        if(n==-1)
            return m+1;
        if(m==-1)
            return n+1;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(w1[n]==w2[m])
            return dp[n][m]=calc(w1,w2,n-1,m-1);
        
        return dp[n][m]=1+min({
            calc(w1,w2,n-1,m),
            calc(w1,w2,n,m-1),
            calc(w1,w2,n-1,m-1)
            });
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        
        return calc(word1,word2,word1.size()-1,word2.size()-1);
    }
};