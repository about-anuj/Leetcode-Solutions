class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),INT_MAX);
        for(auto i:nums){
            auto it=lower_bound(begin(dp),end(dp),i)-begin(dp);
            if(dp[it]>=i)
                dp[it]=i;
        }
        for(int i=0;i<nums.size();i++)
            if(dp[i]==INT_MAX)
                return i;
        return (int)nums.size();
    }
};