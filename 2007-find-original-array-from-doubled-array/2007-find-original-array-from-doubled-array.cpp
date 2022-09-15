class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        unordered_map<int,int>mp;
        sort(begin(c),end(c));
        vector<int>ans;
        for(auto i:c) mp[i]++;
        for(auto i:c)
        {
            if(mp.count(i) and mp.count(2*i))
            {
                mp[i]--;
                mp[2*i]--;
                ans.push_back(i);
                if(mp[i]==0) mp.erase(i);
                if(mp[2*i]==0) mp.erase(2*i);
            }
        }
    
        if(mp.size()!=0) return {};
        return ans;
    }
};