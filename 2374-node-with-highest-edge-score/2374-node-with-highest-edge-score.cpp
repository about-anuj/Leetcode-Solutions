class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long>mp(edges.size()+1);
        long long ans=0,mx=edges.size();
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i]]+=i;
            //ans=max(ans,mp[edges[i]]);
        }
      
        return max_element(begin(mp),end(mp))-begin(mp);
        
    }
};