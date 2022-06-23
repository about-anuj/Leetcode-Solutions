class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
      sort(begin(nums),end(nums));
        int ans=1,cur=1;
        for(int i=1;i<nums.size();i++){
           if(nums[i]!=nums[i-1]){
               if(nums[i]==nums[i-1]+1)
                   cur++;
               else
               {
                   ans=max(ans,cur);
                   cur=1;
               }
           }    
        }
        return max(ans,cur);
    }
};