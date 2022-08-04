class Solution {
    int k;
public:
    vector<vector<int>>ans;
    
    void calc(vector<int>&nums,vector<int>&v,int n,unordered_set<int>&st,int j)
    {
        if(v.size()==k)
        {
            ans.push_back(v);
            return;
        }
        
        for(int i=j;i<nums.size();i++)
        {
            if(st.find(i)==st.end())
            {
                st.insert(i);
                v.push_back(nums[i]);
                calc(nums,v,n,st,i+1);
                st.erase(i);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
       vector<int>nums,v;
        unordered_set<int>st;
        this->k=k;
        for(int i=1;i<=n;i++) nums.push_back(i);
        calc(nums,v,n,st,0);
        return ans;
        
    }
};