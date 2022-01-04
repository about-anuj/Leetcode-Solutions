class Solution {
public:
    int minReorder(int n, vector<vector<int>>& conn) {
        
       for(auto i:conn) 
       {
           g[i[0]].push_back({i[1],1});
           g[i[1]].push_back({i[0],0});
           
       }
        dfs(0);
        return ans;
    }
    private:
    unordered_map<int,int>vis;
    unordered_map<int,vector<pair<int,int>>>g;
    int ans=0;
    
    void dfs(int node)
    {
        vis[node]=1;
        for(auto i:g[node])
        {
            
            
            if(!vis.count(i.first)){
                if(i.second==1)
                ans++;
                
            dfs(i.first);
            }
         }
    }
};