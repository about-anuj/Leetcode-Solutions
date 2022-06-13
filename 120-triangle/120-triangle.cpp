class Solution {
public:
    int dp[201][201];
    int calc(vector<vector<int>>&tr, int n,int i,int j)
    {
        if(i==n-1){
            return dp[i][j]=tr[i][j];
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=tr[i][j]+min(calc(tr,n,i+1,j),calc(tr,n,i+1,j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return calc(triangle,triangle.size(),0,0);
    }
};