class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans(2);
        set<int>s;
        map<int,int>mp;
        for(auto i:matches)
        {
            s.insert(i[0]);
            s.insert(i[1]);
            mp[i[1]]++;
        }

        for(auto i:s)
        {
            if(mp[i]==0 or mp[i]==1)
                ans[mp[i]].push_back(i);
        }
      
        return ans;
    }
};