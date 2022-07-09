class Solution {
public:
    unordered_map<int,bool>dp;
    unordered_set<int>vis;
    bool bfs(vector<int>&v, int cur){
        //if index is out of bound or current index is already visited 
        if(cur>=v.size() or vis.find(cur)!=vis.end())
            return false;
        
        if(v[cur]==0)
            return true;
        
        
        vis.insert(cur);
        if(dp.count(cur))
            return dp[cur];
        
        return dp[cur]=bfs(v,cur+v[cur]) or bfs(v,cur-v[cur]);
    }
    bool canReach(vector<int>& arr, int start) {
        
      return  bfs(arr,start);
    }
};