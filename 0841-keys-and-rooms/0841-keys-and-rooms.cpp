#define pb push_back
class Solution {
public:
    unordered_set<int>st;
    unordered_map<int,vector<int>>g;
    
    void dfs(int i,vector<int>&vis,int src)
    {
      if(vis[i]) 
          return;
      vis[i]=1;
      if(i!=src)
        st.insert(i);
      for(auto j:g[i])
       {
        if(!vis[j])
          dfs(j,vis,src);
       }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int j=0;
        st.insert(0);
        //make graph
        for(auto i:rooms)
        {
            for(auto k:i)
            {
                g[j].pb(k);
            }
            j++;
        }
        
        vector<int>vis(j,0);
        //we have key of room 0
        dfs(0,vis,0);
        return st.size()==j;
    }
};