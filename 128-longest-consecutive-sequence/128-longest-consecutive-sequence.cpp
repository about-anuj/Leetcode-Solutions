class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto i:nums) st.insert(i);
        
        int longest=0;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]-1)==st.end()){
                
                int cur=nums[i];
                int temp=1;
                while(st.count(cur+1))
                {
                    cur++;
                    temp++;
                }
                longest=max(longest,temp);
            }
        }
        return longest;
    }
};