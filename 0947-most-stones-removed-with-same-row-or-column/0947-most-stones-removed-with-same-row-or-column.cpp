class Solution {
public:
    unordered_map<int,vector<int>>mp;
    int dfs(int src,vector<int>&vis)
    {
        if(vis[src]==1) return 0;
        vis[src]=1;
        
        int depth=1;
        for(auto i:mp[src])
        {
            if(vis[i]==0)
                depth+=dfs(i,vis);
        }
        return depth;
        
    }
    int removeStones(vector<vector<int>>& stones) {
        int ans=0,n=stones.size();
        vector<int>vis(n,0);
        for(int i=0;i<stones.size();i++)
        {
            for(int j=0;j<stones.size();j++)
            {
                if(i==j) continue;
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])
                {
                    mp[i].push_back(j);
                }
            }
        }
        for(int i=0;i<stones.size();i++)
        {
            if(vis[i]==0)
            ans+=dfs(i,vis)-1;
        }
        return ans;
    }
};