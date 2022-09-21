class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even=0,j=0;
        vector<int>res(nums.size(),0);
        for(auto i:nums)
            if(i%2==0) even+=i;
        
        for(auto i:queries)
        {
           //we don't care what it was just remove from even if it was even
            if(nums[i[1]]%2==0) even-=nums[i[1]];
            //now add the number
            nums[i[1]]+=i[0];
            
            //if it is now even then include it
            if(nums[i[1]]%2==0)
                even+=nums[i[1]];
            
            res[j++]=even;
        }
        return res;
    }
};