class Solution {
public:
    int minReorder(int n, vector<vector<int>>& conn) {
        
       for(auto i:conn) 
       {
           g[i[0]].push_back(i[1]);
           g[i[1]].push_back(i[0]);
           
           srch.insert({i[0],i[1]});
       }
        dfs(0);
        return ans;
    }
    private:
    unordered_map<int,int>vis;
    set<pair<int,int>>srch;
    unordered_map<int,vector<int>>g;
    int ans=0;
    
    void dfs(int node)
    {
        vis[node]=1;
        for(auto i:g[node])
        {
            
            
            if(!vis.count(i)){
                if(srch.find({node,i})!=srch.end())
                ans++;
                
            dfs(i);
            }
         }
    }
};