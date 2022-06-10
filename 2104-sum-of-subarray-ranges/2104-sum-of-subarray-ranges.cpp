class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int mn=INT_MAX,mx=INT_MIN;
            for(int j=i;j<n;j++)
            {
                mx=max(nums[j],mx);
                mn=min(nums[j],mn);
                
                ans+=(mx-mn);
            }
        }
        return ans;
    }
};