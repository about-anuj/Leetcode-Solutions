class Solution {
public:
    bool dp[100005];
   
    bool winnerSquareGame(int n) {
        memset(dp,false,sizeof(dp));
       // dp[0]=true;
        dp[1]=true;
     for(int i=1;i<=n;i++)
     {
      for(int j=1;j*j<=i;j++)
      {
         if((!dp[i-(j*j)]))
         {
             dp[i]=true;
             break;
         }
      }
     }
        return dp[n];
    }
};