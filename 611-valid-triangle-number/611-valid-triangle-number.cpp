class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size(),ans=0;
        if(n<3) return 0;
        
        sort(begin(nums),end(nums));
        for(int i=n-1;i>=0;i--)
        {
           int l=0,r=i-1;
            while(l<r)
            {
                if(nums[l]+nums[r]>nums[i])
                    ans+=(r-l),r--;
                else
                {
                    l++;
                }
            }
          //  cout<<ans<<endl;
        }
        return ans;
    }
};