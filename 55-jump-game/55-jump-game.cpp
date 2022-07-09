class Solution {
public:
    bool canJump(vector<int>& nums) {
     int ans=0,mxind=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            //if i<=mxind it means there is a place from where we can jump at the cur position
            //if i is greater it means we can't jump this position
           if(i<=mxind) 
             mxind=max(mxind,i+nums[i]); 
        }
        return mxind>=nums.size()-1;
    }
};