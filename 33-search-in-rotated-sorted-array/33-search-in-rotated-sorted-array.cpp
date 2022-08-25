class Solution {
public:
    int search(vector<int>& nums, int tgt) {
        int l=0,r=nums.size()-1;
     
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(nums[mid]==tgt) return mid;
            //there exist rotation
            if(nums[mid]>nums[r])
            {
                if(nums[mid]>tgt and tgt>=nums[l])
                    r=mid-1;
                else
                    l=mid+1;
            }
            else if(nums[mid]<nums[l])
            {
                if(nums[mid]<tgt and tgt<nums[l])
                    l=mid+1;
                else
                    r=mid-1;
            }
            //normail binary search
            else
            {
                if(tgt<nums[mid])
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        return -1;
    }
};