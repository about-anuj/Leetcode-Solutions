class Solution {
public:
    vector<int>dp;
    bool isvalid(vector<int>&nums,int sz,int i)
    {
        if(sz==2) return nums[i]==nums[i+1];
        
        return (nums[i]==nums[i+1] and nums[i+1]==nums[i+2]) or (nums[i+1]==1+nums[i] and nums[i+2]==2+nums[i]);
    }
    bool calc(vector<int>&nums,int i,int n)
    {
       
        if(i==nums.size()) return true;
        if(dp[i]!=-1) return dp[i];
        
        if(i + 1 < n and isvalid(nums,2,i))
        {
            if(calc(nums,i+2,n)) 
                return true;
            
            if(i + 2 < n and isvalid(nums,3,i))
                if(calc(nums,i+3,n))
                    return true;
        }
        if(i + 2 < n and isvalid(nums,3,i))
            if(calc(nums,i+3,n))
                return true;
        
        return dp[i]=false;
    }
        bool validPartition(vector<int>& nums) {
       // vector<int>v;
            dp.resize(nums.size()+1,-1);
        return calc(nums,0,nums.size());
    }
};
