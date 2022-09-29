class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int col[101]={0};
        int vis[101]={0};
        
        queue<int>q;
        for(int i=0;i<graph.size();i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                q.push(i);
                while(!q.empty())
                {
                    int cur=q.front();
                       q.pop();
                      for(auto j:graph[cur])
                      {
                          if(vis[j]==0)
                          {
                           col[j]=col[cur]==0?1:0;
                           vis[j]=1;
                           q.push(j);
                           }
                       //if we got same color
                            else if(vis[j]==1 and col[cur]==col[j]){
                              cout<<cur;  
                              return 0;
                             }
                       }
                }
            }
        }
        return 1;
    }
};