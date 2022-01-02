class Solution {
public:
    void dfs(int src)
    {
        if(found==false)
            return;
        count++;
        vis[src]=1;
        for(auto i:g[src])
        {
            if(!vis.count(i))
                dfs(i);
            else{
              found=false;
                return;
            }
        }
        
    }
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rt) {
       
        vector<int>in(n,0);
     for(int i=0;i<n;i++)
     {
       if(lc[i]!=-1){
           in[lc[i]]++;
           g[i].push_back(lc[i]);
       }
       if(rt[i]!=-1){
           in[rt[i]]++;
           g[i].push_back(rt[i]);
       }
     }
        
       for(int i=0;i<n;i++){
           if(in[i]==0){
               dfs(i);
            return found and count==n;
           }
       }
           return false;
    }
    private:
    unordered_map<int,vector<int>>g;
    unordered_map<int,int>vis;
    bool found=true;
    int count=0;
};