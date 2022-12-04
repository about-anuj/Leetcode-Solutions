class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size(),ans=INT_MAX,res;
        long long second=accumulate(begin(nums),end(nums),0ll),first=0;
       
        for(int i=0;i<n;i++)
        {
            first+=nums[i];
            second-=nums[i];
            int a1=first/(i+1),a2=0;
            if(i<n-1)
            a2=second/(n-i-1);
            if(ans>abs(a2-a1))
            {
                ans=abs(a2-a1);
                res=i;
            }
        }
        return res;
    }
};