class Solution {
public:
    int findst(vector<int>&nums,int i,int j,int tgt){
        while(i<j){
            int mid=(i+j)/2;
            if(nums[mid]>=tgt)
                j=mid;
            else
                i=mid+1;
        }
       // if(nums[j]!=tgt) return -1;
        return j;
    }
    int findend(vector<int>&nums,int i,int j,int tgt){
        while(i<j){
            int mid=(i+j)/2+1;
            if(nums[mid]<=tgt)
                i=mid;
            else
                j=mid-1;
        }
     //   if(nums[j]!=tgt) return -1;
        return j;
    }
    vector<int> searchRange(vector<int>& nums, int tgt) {
        int st=-1,end=-1,n=nums.size();
       st= findst(nums,0,nums.size()-1,tgt);
        if(st>=0 and st<n and nums[st]!=tgt) return {-1,-1};
       end=findend(nums,0,nums.size()-1,tgt);
        return {st,end};
    }
};