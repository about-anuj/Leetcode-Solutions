class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        string s2;
      int n=s1.size();
        int dp[n+1][n+1];
        for(int i=n-1;i>=0;i--)
            s2+=s1[i];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
        return 0;
    }
};