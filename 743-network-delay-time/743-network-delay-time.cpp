typedef pair<int,int>pii;
class Solution {
public:
   
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     for(auto i:times)
     {
         mp[i[0]].push_back({i[1],i[2]});
     }
     vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
     pq.push({0,k});
        while(!pq.empty())
        {
            pii p=pq.top(); pq.pop();
            int u=p.second;
            for(auto& i:mp[u])
            {
                int v=i.first,w=i.second;
                if(dist[v]>dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=*max_element(begin(dist)+1,end(dist));
      //  for(int i=0;i<dist.size();i++) cout<<dist[i]<<" ";
        return ans==INT_MAX?-1:ans;
    } 
    
    private:
    unordered_map<int,vector<pii>>mp;
    bool vis[105]={false};
    priority_queue<pii,vector<pii>,greater<pii>>pq;
};