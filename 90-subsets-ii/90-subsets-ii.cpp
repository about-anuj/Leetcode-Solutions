class Solution {
public:
    vector<vector<int>>ans;
    void calc(vector<int>&nums, int i,int n,vector<int>v)
    {
         if(i>n) return;
        
      //  sort(v.begin(),v.end());
        if(find(ans.begin(),ans.end(),v)==ans.end())
        ans.push_back(v);
        for(int j=i;j<n;j++)
        {
            v.push_back(nums[j]);
            calc(nums,j+1,n,v);
            v.pop_back();
        }
    }
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        calc(nums,0,nums.size(),{});
        return ans;
    }
};