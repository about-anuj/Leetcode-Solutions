//if the graph contains cycle and it is of odd length then then graph will not bipirate 
//otherwise it will bipirate.
//PARALLY WE CAN SAY TAHT IF TWO ADJACENT NODE HAVE SAME COLOR THAN THEY WILL NOT BIPARTITE
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        vector<int>col(102,0);
        
        //iterate in loop to avoid disconnected compoent bug
        for(int i=0;i<g.size();i++){
            //if already visited then continue 
            if(vis[i]) continue;
           //first time we will come here second time we will only come here in case of 
            //disconnected component so for it we have to start process again
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
                    //color neighbour with different color
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
    unordered_map<int,int>vis;
};
