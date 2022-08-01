class Solution {
public:
    vector<int>vis;
    int dfs(int src,vector<int>&e,vector<int>&indeg,vector<int>& outdeg)
    {
        int len=0;
        unordered_map<int,int>mp;
        while(src!=-1 and outdeg[src]>0 and indeg[src]>0)
        {
            if(mp.count(src)) return len-mp[src];
            
            if(vis[src]==1) break;
            vis[src]=1;
            mp[src]=len++;
            src=e[src];
        }
        return -1;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size(),cycle_len=-1;
        vis.assign(n,-1);
        vector<int>indeg(n,0),outdeg(n,0);
        
        for(int i=0;i<edges.size();i++)
            if(edges[i]!=-1)
            indeg[edges[i]]++;
        
        for(int i=0;i<edges.size();i++)
            if(edges[i]!=-1)
               outdeg[i]++;
      
        // for(auto i:indeg) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:outdeg) cout<<i<< " ";
        for(int i=0;i<n;i++)
        {
            //if indeg and outdeg >0 means it is a part of cycle
            if(indeg[i]>0 and outdeg[i]>0 and vis[i]==-1)
            {
              //  cout<<i<<" ";
                cycle_len=max(cycle_len,dfs(i,edges,indeg,outdeg));
            }
        }
        //if(cycle_len==INT_MAX) return -1;
        return cycle_len;
    }
};