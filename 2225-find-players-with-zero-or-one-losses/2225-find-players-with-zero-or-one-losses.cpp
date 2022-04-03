class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans;
        unordered_map<int,int>mp;
        for(auto i:matches)
        {
            mp[i[0]]=0;
            mp[i[1]]=0;
            
        }
        for(auto i:matches)
        {
            mp[i[1]]++;
        }
        vector<int>v1,v2;
        for(auto i:mp)
        {
            if(i.second==0)
                v1.push_back(i.first);
            if(i.second==1)
                 v2.push_back(i.first);
        }
        sort(begin(v1),end(v1));
        sort(begin(v2),end(v2));
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};