#define pb push_back
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
     unordered_map<int,vector<int>>g;
        vector<int>vis(n,0);
        for(auto i:edges)
        {
            g[i[0]].pb(i[1]);
            g[i[1]].pb(i[0]);
        }
        queue<int>q;
        q.push(source);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            if(cur==destination)
                return 1;
            
            for(auto node:g[cur])
            {
                if(!vis[node])
                {
                    vis[node]=1;
                    q.push(node);
                }
            }
        }
        return 0;
    }
};