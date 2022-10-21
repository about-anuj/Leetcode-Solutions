class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>st;
        // return 0;
        int i=0,j=0;
        if(k<=0) return 0;
        while(j<nums.size())
        {
          if(j-i-1<=k)
          {
              // cout<<j<<" ";
              
              if(st.find(nums[j])!=st.end()) 
                  return true;
              
              if(j-i==k) st.erase(nums[i++]);
              st.insert(nums[j++]);
          }
        }
        return false;
    }
};