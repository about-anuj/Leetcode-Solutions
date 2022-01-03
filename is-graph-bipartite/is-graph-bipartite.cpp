//if the graph contains cycle and it is of odd length then then graph will not bipirate 
//otherwise it will bipirate.
//PARALLY WE CAN SAY TAHT IF TWO ADJACENT NODE HAVE SAME COLOR THAN THEY WILL NOT BIPARTITE
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //make the graph
        for(int i=0;i<graph.size();i++)
        {
            for(auto j:graph[i])
            {
                g[i].push_back(j);
            }
        }
        
        queue<int>q;
        vector<int>col(102,0);
        
        for(int i=0;i<graph.size();i++){
            if(col[i]) continue;
        col[0]=1;
        vis[0]++;
        q.push(i);
        while(!q.empty())
        {
            int f=q.front();  q.pop();
            for(auto i:g[f])
            {
                //if a edge is already visited 
              if(vis.count(i) and col[i]==col[f])
                  return false;
                else if(!vis.count(i))
                {
                    vis[i]++;
                    col[i]=(col[f]==1?-1:1);
                    q.push(i);
                }
            }
        }
        }
        //for disconnected component
        //for(int i=0;i<graph.size();i++) if(col[i]==-1)return false;
        
        return true;
    }
    private:
    int len=0;
    unordered_map<int,vector<int>>g;
    unordered_map<int,int>vis;
};