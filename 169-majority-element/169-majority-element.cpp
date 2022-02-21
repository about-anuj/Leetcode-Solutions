class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0,ans;
        for(auto i:nums)
        {
         if(c==0)
             ans=i;
          
             c+= (i==ans)?1:-1;
        }
        return ans;
    }
};