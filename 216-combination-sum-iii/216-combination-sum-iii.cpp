class Solution {
public:
    set<vector<int>>st;
    void solve(int cur, int k, int total, vector<int>&v){
        if(k==0 and total==0){
           st.insert(v);
            return;
        }
        
        if(k==0 and (total<0 or total>0))
            return;
        
        for(int i=cur;i<=9;i++){
            
            v.push_back(cur);
            solve(i+1,k-1,total-cur,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        vector<vector<int>>ans;
        
        for(int i=1;i<=9;i++)
        solve(i,k,n,v);
        
        for(auto i:st) ans.push_back(i);
        
        return ans;
    }
};