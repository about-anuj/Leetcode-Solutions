class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),ans=0,cur=0;
        if(n<=2) return 0;
        
        for(int i=1;i<n-1;i++)
        {
            if(2*nums[i]==nums[i-1]+nums[i+1])
            {
              cur+=1;
              ans+=cur;
            }
            else{
                cur=0;
            }
        }
        return ans;
    }
};