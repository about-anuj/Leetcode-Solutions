class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // int last[31]={0};
        vector<int>res(nums.size(),0),last(30,0);
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=0;j<30;j++)
            {
                if(nums[i] & (1<<j))
                {
                    last[j]=i;
                }
            }
            res[i]=max(1,*max_element(begin(last),end(last))-i+1);
        }
        return res;
    }
};