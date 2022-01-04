class Solution {
public:
    vector<int>parent;
    unordered_map<int,vector<int>>g;
    int find(int i)
    {
        while(i!=parent[i])
            i=parent[i];
            
            return parent[i];
    }
    void unon(int a,int b)
    {
        parent[find(a)]=find(b);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(1002,-1);
        for(int i=0;i<1002;i++)
            parent[i]=i;
        
        for(auto i:edges)
        {
            if(find(i[0])==find(i[1])) return i;
            else
                unon(i[0],i[1]);
        }
        return {};
    }
};