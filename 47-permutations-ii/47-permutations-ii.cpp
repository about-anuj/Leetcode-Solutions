class Solution {
public:
    vector<vector<int>>ans;
    
    void calc(vector<int>nums,int cur,int n)
    {
        if(cur==n)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=cur;i<=n;i++)
        {
           swap(nums[i],nums[cur]);
           calc(nums,cur+1,n);
           swap(nums[i],nums[cur]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        calc(nums,0,nums.size()-1);    
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};