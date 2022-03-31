class Solution {
public:
    long long dp[1005][53];
   // int ans=0;
   long long calc(vector<int>&nums,int m,int i)
    {
      long long ans = INT_MAX;  // Answer of the current state
        long long sum = 0;
        if(m==1)
        {
            return accumulate(begin(nums)+i,end(nums),0LL);
        }
        if(dp[i][m]!=-1) return dp[i][m];
        
        for(int j=i;j<nums.size();j++)
        {
            sum+=nums[j];
            ans=min(ans,max(sum,calc(nums,m-1,j+1)));
        }
        return dp[i][m]=ans;
    }
    int splitArray(vector<int>& nums, int m) {
        memset(dp,-1,sizeof(dp));
        return calc(nums,m,0);
        
    }
};


  