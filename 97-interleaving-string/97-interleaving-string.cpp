class Solution {
public: 
    int dp[105][105];
    bool calc(string &s1,string &s2,string &s3,int i, int j, int k, int n, int m, int l){
        
        if(i==n and j==m and k==l)
            return dp[i][j]=true;
        
       if(dp[i][j]!=-1) return dp[i][j];
        //if element equal then either took or not
        if(i<n and s1[i]==s3[k] and j<m and s2[j]==s3[k])
            return dp[i][j]=calc(s1,s2,s3,i+1,j,k+1,n,m,l) or calc(s1,s2,s3,i,j+1,k+1,n,m,l);
        else if(j<m and s2[j]==s3[k])
            return dp[i][j]=calc(s1,s2,s3,i,j+1,k+1,n,m,l) ;
        else if(i<n and s1[i]==s3[k])
            return dp[i][j]=calc(s1,s2,s3,i+1,j,k+1,n,m,l);
        return false;    //no character matched it means we took wrong number of chars previous
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return calc(s1,s2,s3,0,0,0,s1.size(),s2.size(),s3.size());
    }
};