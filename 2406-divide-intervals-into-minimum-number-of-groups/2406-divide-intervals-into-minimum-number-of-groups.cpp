class Solution {
public:
    int minGroups(vector<vector<int>>& inter) {
        sort(begin(inter),end(inter));
        int mx=0,t=0;
        
        vector<vector<int>>pre;
        for(auto i:inter)
        {
            pre.push_back({i[0],1});
            pre.push_back({i[1]+1,-1});
        }
        sort(begin(pre),end(pre));
        // int mx=0;
        for(auto i:pre)
        {
            t+=i[1];
            mx=max(mx,t);
        }
        return mx;
    }
};