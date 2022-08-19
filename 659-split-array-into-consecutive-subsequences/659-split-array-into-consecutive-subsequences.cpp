class Solution {
public:
   
    bool isPossible(vector<int>& nums) {
        vector<vector<int>>v;
       // each integer is exactly one more than the previous integer
        for(int i=0;i<nums.size();i++)
        {
         //   sort(begin(v),end(v),cmp);
            int k;
            for(k=v.size()-1;k>=0;k--)
            {
                if(v[k].back()+1==nums[i])
                {
                    v[k].push_back(nums[i]);
                    break;
                }   
            }
            if(k==-1)
              v.push_back({nums[i]});
        }
        
        for(auto i:v)
           if(i.size()<3) return false;
        
        return true;
    }
};