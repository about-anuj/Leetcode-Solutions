#define pb push_back
class Solution {
public:
    //check bipertite graph only
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
      vector<int>col(n+1,0),vis(n+1,0);
      unordered_map<int,vector<int>>g;
        for(auto i:dislikes)
        {
            g[i[0]].pb(i[1]);
            g[i[1]].pb(i[0]);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
               queue<int>q;
                q.push(i);
                col[i]=1;
                vis[i]=1;
                while(!q.empty())
                {
                    int par=q.front(); q.pop();
                    for(auto child:g[par])
                    {
                        if(col[par]==col[child] and vis[child]==1)
                            return 0;
                        if(vis[child]==0)
                        {
                           q.push(child);
                           vis[child]=1; 
                           col[child]=1-col[par];
                        }
                    }
                }
            }
        }
        return 2;
    }
};