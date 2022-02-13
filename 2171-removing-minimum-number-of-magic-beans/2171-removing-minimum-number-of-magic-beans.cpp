class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        long n=nums.size(),pivot=-1;
        long long ans=LLONG_MAX;
        sort(begin(nums),end(nums));
 
        long sum=accumulate(begin(nums),end(nums),0L);
        for(int i=0;i<n;i++)
        {
          long long x=sum-(n-i)*nums[i];
            if(x<ans)
                ans=x;    
        }
        
       
        
        return ans;
    }
};