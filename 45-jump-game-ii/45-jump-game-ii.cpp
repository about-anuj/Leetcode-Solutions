class Solution {
public:
    int jump(vector<int>& nums) {
           
       int lst=1;
        vector<int>dp(nums.size(),-1);
        dp[0]=0;
        for(int i=0;i<nums.size();i++)
        {
            int prev=dp[i];
            //if(i+dp[i]<lst)
            for(int j=lst;j<=i+nums[i] and j<nums.size();j++)
            {
                dp[j]=prev+1;
                lst=j+1;
            }
        }
        // for(auto i:dp)
        //     cout<<i<<" ";
        return dp[nums.size()-1];
    }
};