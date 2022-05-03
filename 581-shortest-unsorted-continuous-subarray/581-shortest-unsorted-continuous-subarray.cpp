class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      int mn=INT_MAX,mx=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            
            if(i<nums.size()-1 and nums[i]>nums[i+1])
            {
                mn=min(mn,nums[i]);
                mx=max(mx,nums[i]);
            }
            
             if(i>0 and nums[i]<nums[i-1])
            {
                mn=min(mn,nums[i]);
                mx=max(mx,nums[i]);
            }
        }
        
        int i,j,n=nums.size();
        
       for(i=0;i<n and nums[i]<=mn;i++);
       for(j=n-1;j>=0 and nums[j]>=mx;j--);
        
        return j-i+1>0?j-i+1:0;
    }
};