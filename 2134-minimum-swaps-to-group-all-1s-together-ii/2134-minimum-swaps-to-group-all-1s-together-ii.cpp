class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int windsz=0;
        for(auto i:nums)
            if(i==1)
                windsz++;
        
        int st=0,end=0,n=nums.size(),windsm=0,res=INT_MAX;
       for(int i=0,j=0;i<n;i++){
           while(j-i<windsz)
               windsm+=nums[j++ % n];
           
           res=min(res,windsz-windsm);
           windsm-=nums[i];
       }
        return res;
    }
};