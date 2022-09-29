class Solution {
public:
    int col[101];
    bool dfs(int i,vector<vector<int>>&graph,vector<int>&vis)
    {
        vis[i]=1;
        for(auto j:graph[i])
        {
            if(vis[j]==0)
            {
                col[j]=col[i]==1?0:1;
                if(!dfs(j,graph,vis))
                    return false;
            }
            else if(col[i]==col[j])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //BFS
//         int col[101]={0};
//         int vis[101]={0};
        
//         queue<int>q;
//         for(int i=0;i<graph.size();i++)
//         {
//             if(vis[i]==0)
//             {
//                 vis[i]=1;
//                 q.push(i);
//                 while(!q.empty())
//                 {
//                     int cur=q.front();
//                        q.pop();
//                       for(auto j:graph[cur])
//                       {
//                           if(vis[j]==0)
//                           {
//                            col[j]=col[cur]==0?1:0;
//                            vis[j]=1;
//                            q.push(j);
//                            }
//                        //if we got same color
//                             else if(vis[j]==1 and col[cur]==col[j]){
//                               cout<<cur;  
//                               return 0;
//                              }
//                        }
//                 }
//             }
//         }
//         return 1;
        
    //DFS
        memset(col,0,sizeof(col));
      vector<int>vis(101,0);
        for(int i=0;i<graph.size();i++)
        {
          if(vis[i]==0)
          {
              if(!dfs(i,graph,vis))
                  return 0;
          }
        }
        return 1;
    }
};