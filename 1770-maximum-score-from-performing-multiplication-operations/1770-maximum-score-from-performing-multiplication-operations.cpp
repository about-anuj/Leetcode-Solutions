class Solution {
public:
    int dp[1001][1001];
    int recur(vector<int>&nums,vector<int>&multi,int i,int end,int j)
    {
        if(j>=multi.size() or end<0) return 0;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        return dp[i][j]= max(recur(nums,multi,i+1,end,j+1)+nums[i]*multi[j],
                  recur(nums,multi,i,end-1,j+1)+nums[end]*multi[j]);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        for(int i=0;i<1001;i++)
            for(int j=0;j<1001;j++)
                dp[i][j]=INT_MIN;
        return recur(nums,multipliers,0,nums.size()-1,0);
    }
};