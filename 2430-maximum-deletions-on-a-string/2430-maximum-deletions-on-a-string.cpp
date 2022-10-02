class Solution {
public:
    int dp[10005];
    int calc(int i,string &s)
    {
        if(dp[i]!=-1) return dp[i];   
        int x=1;
        for(int len=1;i+2*len<=s.size();len++)
        {
           if (s.compare(i, len, s, i + len, len) == 0)
                x = max(x, 1 + calc(i + len, s)); 
        }
        return dp[i]=x;
    }
    int deleteString(string s) {
        memset(dp,-1,sizeof(dp));
        return calc(0,s);
    }
};
// int dp[40000] = {};
// int dfs(int i, string &s) {
//     if (dp[i] == 0) {
//         dp[i] = 1;
//         for (int len = 1; i + 2 * len <= s.size(); ++len)
//             if (s.compare(i, len, s, i + len, len) == 0)
//                 dp[i] = max(dp[i], 1 + dfs(i + len, s));
//     }
//     return dp[i];
// }
// int deleteString(string s) {
//     return dfs(0, s);
// }