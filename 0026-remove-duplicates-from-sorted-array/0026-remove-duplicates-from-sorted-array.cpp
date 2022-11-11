class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,n=nums.size();
        for(int j=0;j<n;j++)
        {
            nums[i]=nums[j];
            if(i>0 and nums[i]==nums[i-1])
                i--;
            
            i++;
        }
        return i;
    }
};