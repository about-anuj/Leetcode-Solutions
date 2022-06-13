class Solution {
public:
    int dp[201][201];
//     int calc(vector<vector<int>>&tr, int n,int i,int j)
//     {
//         if(i==n-1){
//             return dp[i][j]=tr[i][j];
//         }
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         return dp[i][j]=tr[i][j]+min(calc(tr,n,i+1,j),calc(tr,n,i+1,j+1));
    // }
    
   
    
    int minimumTotal(vector<vector<int>>& tr) {
        vector<vector<int>>dp(tr.size(),vector<int>(tr.size(),0));
        int ans=INT_MAX;
        dp[0][0]=tr[0][0];
        for(int i=1;i<tr.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0) dp[i][j]=tr[i][j]+dp[i-1][j];
                else if(j==i) dp[i][j]=tr[i][j]+dp[i-1][j-1];
                else dp[i][j]=tr[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            }
        }
        for(auto i:dp[tr.size()-1])
            ans=min(i,ans);
        
        return ans;
    }
};