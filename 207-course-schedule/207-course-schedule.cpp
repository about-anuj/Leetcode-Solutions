class Solution {
public:
    int vis[2001],dfsvis[2001];
    bool dfs(int i,unordered_map<int,vector<int>>&g)
    {
        if(dfsvis[i]) return true;
        if(vis[i]) return false;
        
        vis[i]=1;
        dfsvis[i]=1;
        for(auto cur:g[i])
        {
            if(!vis[cur]){
               if(dfs(cur,g))
                   return true;
            }
            else if(dfsvis[cur]==1)
                return true;
        }
        dfsvis[i]=0;
        return false;
    }
    bool canFinish(int c, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>>g;
        memset(vis,0,sizeof(vis));
        memset(dfsvis,0,sizeof(dfsvis));
        for(auto i:pre){
            g[i[0]].push_back(i[1]);
        }
        
        for(int i=0;i<c;i++)
        {
            if(vis[i]==0)
            {
              if(dfs(i,g)) 
              return 0;
            }
        }
        return 1;
    }
};