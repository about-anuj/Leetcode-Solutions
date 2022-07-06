class Solution {
public: 
    vector<vector<int>>ans;
     vector<int>v;
    void solve(vector<int>&g, int tgt,int i, int n,int sum)
    {
       if(sum==tgt)
         {
         ans.push_back(v);
         return;
         }
        
        for(int j=i;j<n;j++){
            if(j>i and g[j]==g[j-1]) continue;
            if(sum+g[j]>tgt) break;
            
            v.push_back(g[j]);
            solve(g,tgt,j+1,n,sum+g[j]);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& g, int tgt) {
        sort(g.begin(),g.end());
       solve(g,tgt,0,g.size(),0);
       return ans;
    }
};