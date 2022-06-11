class Solution {
public:
   
    int minOperations(vector<int>& nums, int x)
    {
       int total=accumulate(begin(nums),end(nums),0);
        if(x>total) return -1;
        int sub_sum=total-x,cur=0;
        int j=0,ans=INT_MIN;   
        for(int i=0;i<nums.size();i++)
        {
            cur+=nums[i];
            while(j<nums.size() and cur>sub_sum)
                cur-=nums[j++];
            
            if(cur==sub_sum)
                ans=max(ans,i-j+1);
        }
        if(ans==INT_MIN) return -1;
        
        return nums.size()-ans;
    }
};