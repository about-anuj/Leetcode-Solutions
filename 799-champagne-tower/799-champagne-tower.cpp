class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[105][105]={0.0};
        dp[0][0]=double(poured); //all glasses will go through first glass;
        
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
              //  double q=(dp[i][j]-1.0)/2.0;
                if(dp[i][j]>=1)
                {
                    dp[i+1][j]+=(dp[i][j]-1.0)/2.0;
                    dp[i+1][j+1]+=(dp[i][j]-1.0)/2.0;
                    dp[i][j]=1;
                }
            }
        }
        
        return dp[query_row][query_glass];
    }
};