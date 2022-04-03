class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;
        if(n==2){
            swap(nums[0],nums[1]);
            return;
          }
        
        int i=n-2;
        while(i>=0 and nums[i]>=nums[i+1]) i--;
        
        if(i==-1) reverse(begin(nums),end(nums));
        else{
            int prev=i;
            int j=n-1;
            while(nums[j]<=nums[i]) j--;
            swap(nums[j],nums[i]);
            sort(begin(nums)+i+1,end(nums));
        }
        
    }
};