class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even=0,odd=0,j=0;
        vector<int>res(nums.size(),0);
        for(auto i:nums)
            if(i%2==0) even+=i;
            else odd+=i;
        
        for(auto i:queries)
        {
          if((nums[i[1]]+i[0])%2==0)
          {
              if(nums[i[1]]%2==0)
                  even+=i[0];
              else
              {
                  odd-=nums[i[1]];
                  even+=(nums[i[1]]+i[0]);
              }
          }
          else
          {
              if((nums[i[1]])%2==0)
              {
                  even-=nums[i[1]];
                  odd+=nums[i[1]]+i[0];
              }
          }
            nums[i[1]]+=i[0];
            res[j++]=even;
        }
        return res;
    }
};