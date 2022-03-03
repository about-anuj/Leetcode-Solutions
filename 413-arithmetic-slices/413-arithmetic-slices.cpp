class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),ans=0;
        if(n<=2) return 0;
        
        for(int i=1;i<n-1;i++)
        {
            if(2*nums[i]==nums[i-1]+nums[i+1])
            {
               int j=i-1;
               while(i<n-1 and 2*nums[i]==nums[i-1]+nums[i+1])
                   i++;
                
               // i++;
                int len=(i-j);
                len-=1; //minimum size is 2 and after it we can simply apply formula
                
                if(len>=0){
                    ans+=(len*(len+1))/2;
                }
                
            }
        }
        return ans;
    }
};