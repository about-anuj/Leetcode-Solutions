class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=(int)nums.size(),c=0,mn=INT_MAX;

        //set the elements which are out of range
        for(int i=0;i<n;i++)
        { 
            if(nums[i]==1)
                c=1;
            
            if(nums[i]<=0 or nums[i]>n)
                nums[i]=1;
            
        }
        
        if(c==0)
            return 1;
        
        for(int i=0;i<n;i++){
            int ind=abs(nums[i]);
            nums[ind-1]=-1*abs(nums[ind-1]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                return i+1;
        }
         return n+1;
    }
};