class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int mn=INT_MAX;
        int n=nums.size(),ans=0;
        for(int i=0;i<n-2;i++)
        {
            int j=i+1,k=n-1;
            if(i>0 and nums[i-1]==nums[i]) continue;
            while(j<k)
            {
                int x=nums[i]+nums[j]+nums[k];
                if(abs(target-x)<mn){
                    mn=abs(target-x);
                    ans=x;
               }
                else if(x>target)
                   k--;
                else
                    j++;
            }
        }
        return ans;
    
    }
};