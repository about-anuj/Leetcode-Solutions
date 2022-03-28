class Solution {
public:
    bool search(vector<int>& nums, int tgt) {
        int l=0,r=nums.size()-1,n=nums.size();
        while(l<=r)
        {
            while(l<r and nums[l]==nums[l+1]) l++;
            while(r>l and nums[r]==nums[r-1]) r--;
           int mid=l+(r-l)/2;
        
            if(nums[mid]==tgt) return 1;
            
            //list is in order
           if(nums[l]<=nums[mid])
            {
               if(tgt>=nums[l] and nums[mid]>tgt) r=mid-1;
               else l=mid+1;
            }
           else 
           {
             if(tgt<=nums[r] and nums[mid]<tgt) l=mid+1;
               else r=mid-1;
           }
        }
        return 0;
        
        
        // else if(nums[left] <= nums[mid])
        //     {
        //         if( (nums[left]<=target) && (nums[mid] > target) ) right = mid-1;
        //         else left = mid + 1; 
        //     }
        //     else
            //{
               // if((nums[mid] < target) &&  (nums[right] >= target) ) left = mid+1;
                //else right = mid-1;
           // }
    }
};