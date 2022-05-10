class Solution {
public:
    vector<vector<int>>ans;
    void calc(int k, int n, int cur,vector<int>&v,int sum)
    {
        if(sum==n and v.size()==k)
        {
            if(find(ans.begin(),ans.end(),v)==ans.end())
            ans.push_back(v);
            return;
        }
        
        if(v.size()==k and (sum<n or sum>n)) return;
        
        for(int i=cur;i<=9;i++)
        {
            v.push_back(cur);
            calc(k,n,i+1,v,sum+cur); 
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>v;
        for(int i=1;i<=9;i++)
        calc(k,n,i,v,0);
        return ans;
    }
};