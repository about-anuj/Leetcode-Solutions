class Solution {
public:
    int earliestFullBloom(vector<int>& pl, vector<int>& gr) {
        vector<pair<int,int>>v;
        int ans=0,st=0;
        for(int i=0;i<pl.size();i++)
        {
            v.push_back({gr[i],pl[i]});
        }
        sort(begin(v),end(v));
        reverse(begin(v),end(v));
        
        for(int i=0;i<pl.size();i++)
        {
            st+=v[i].second;
            ans=max(ans,st+v[i].first);
        }
        return ans;
    }
};