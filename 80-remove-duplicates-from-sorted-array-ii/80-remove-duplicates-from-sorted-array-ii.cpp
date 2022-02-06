class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),c=0;
        for(int i=2;i<n;i++)
        {
            if(nums[i]==nums[i-2-c]) c++;
            else
                nums[i-c]=nums[i];
        }
        return n-c;
    }
};