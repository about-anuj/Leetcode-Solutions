class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mnk, int mxk) {
        long long res=0,mod=1e9+7;
        bool mxfind=false,mnfind=false;
        int start=0,mxl=0,mnl=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mnk or nums[i]>mxk)
            {
                mxfind=false;
                mnfind=false;
                start=i+1;
            }
            if(nums[i]==mnk)
            {
                mnl=i;
                mnfind=true;
            }
            if(nums[i]==mxk)
            {
                mxl=i;
                mxfind=true;
            }
            if(mnfind and mxfind)
                res=(res+min(mnl,mxl)-start+1);
        }
        return res;
    }
};