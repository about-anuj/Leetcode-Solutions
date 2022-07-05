class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int ans=0;
        for(auto i:nums) st.insert(i);
        
        for(auto i:nums){
            if(!st.count(i-1))
            {
                int j=i;
                while(st.count(j++))
                    
                    ans=max(ans,j-i);
            }
        }
        return ans;
    }
};