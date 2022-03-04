class Solution {
public:
    double dp[101][101];
    double solve(int filled,int r,int c){
        if(r==0 and c==0) return filled;
        if(c<0 or c>r or r<0) return 0.0;
        
        if(dp[r][c]>-1.0)
            return dp[r][c];
        
        double x=max((solve(filled,r-1,c-1)-1)/2,double(0));
        double y=max((solve(filled,r-1,c)-1)/2,double(0));
        
        return dp[r][c]=x+y;
    }
    double champagneTower(int filled, int r, int c) {
       memset(dp,-1.0,sizeof(dp));
       return min(solve(filled,r,c),double(1));
    }
};