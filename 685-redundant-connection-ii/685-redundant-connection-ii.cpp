class Solution {
public: 
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        bool intwo=false;
        vector<int>b1,b2,f={0,0};
        
        vector<int>indeg(1001,0);
        unordered_map<int,int>mp;
       for(auto i:edges)
       {
           indeg[i[1]]++;
           if(indeg[i[1]]==2)
           {
               intwo=true;
               b1={mp[i[1]],i[1]};
               b2=i;
           }
           mp[i[1]]=i[0];
       }
        
        if(!intwo) return detect(edges,f);
        if(detect(edges,b2)==f) return b2;
        return b1;
    }
 
    
    
    int find(int x,vector<int>&parent)
    {
        if(parent[x]==x) return x;
       parent[x]=find(parent[x],parent);
        
        return parent[x];
    }
     
    void unon(int a,int b,vector<int>&parent)
    {
        a=find(a,parent);
        b=find(b,parent);
        if(a==b) return;
        parent[b]=a;
    }
    
    vector<int> detect(vector<vector<int>>&edges,vector<int>&f){
        vector<int>parent(1002,-1);
        
        for(int i=0;i<1002;i++)
            parent[i]=i;
        
        for(auto i:edges)
        {
            if(i==f) continue;
            int a=i[0],b=i[1];
            if(find(a,parent)==find(b,parent)) 
                return i;
            
            unon(a,b,parent);
        }
        return {0,0};
    }
};











