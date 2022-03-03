class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),ans=0;
        if(n<=2) return 0;
        
        for(int i=1;i<n-1;i++)
        {
            if(2*nums[i]==nums[i-1]+nums[i+1])
            {
               int len=0;
               while(i<n-1 and 2*nums[i]==nums[i-1]+nums[i+1])
                  len++, i++;
                
                if(len>=0){
                    ans+=(len*(len+1))/2;
                }
                
            }
        }
        return ans;
    }
};