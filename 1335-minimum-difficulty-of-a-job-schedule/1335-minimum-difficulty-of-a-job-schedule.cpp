class Solution {
public:
    int dp[301][11];   //jobdifficult and days
    long long calc(int i,int n,vector<int>&jobs,int d)
    {
        //base case
        //no day remaining and whole work done
        if(i==n and d==0) return 0;
        //days remaining and tasks complete
        if(i==n and d>0) return INT_MAX;
        //task remaining and days complete 
        if(i<n and d==0) return INT_MAX;
        
        
        if(dp[i][d]!=-1) return dp[i][d];
        long long daymax=INT_MIN,wholemin=INT_MAX;
        for(int j=i;j<n;j++)
        {
            daymax=max(daymax,(long long)jobs[j]);
            wholemin=min(wholemin,daymax+calc(j+1,n,jobs,d-1));
        }
        return dp[i][d]=wholemin;
    }
    int minDifficulty(vector<int>& jobs, int d) {
        if(jobs.size()<d) return -1;
        memset(dp,-1,sizeof(dp));
        return (int)calc(0,jobs.size(),jobs,d);
    }
};