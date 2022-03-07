class Solution {
public:
    int calc(vector<int>&nums,int val){
        int n=nums.size(),ans=0;
        for(auto i:nums)
        {
            if(i!=val)
                ans+=abs(i-val);
        }
        return ans;
    }
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        
        if(nums.size()%2!=0){
          return  calc(nums,nums[nums.size()/2]);
        }
        else
          return min(calc(nums,nums[nums.size()/2]),calc(nums,nums[nums.size()/2-1]));  
    }
};