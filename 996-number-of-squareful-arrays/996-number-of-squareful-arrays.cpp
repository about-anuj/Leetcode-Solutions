class Solution {
public:
    unordered_map<int,int>mp;
     vector<int>cur;
    vector<vector<int>>ans;
     bool isSquare(int v) {
        int r = sqrt(v);
        return r * r == v;
     }
    void calc(int i,int n){
        if(i==n)
        {
            if(find(begin(ans),end(ans),cur)==ans.end())
            ans.push_back(cur);
            return;
        }
        
        for(auto& k:mp){
            if(k.second==0) continue;
            if(cur.empty() or isSquare(cur.back()+k.first))
            {
            cur.push_back(k.first); k.second--;
            calc(i+1,n);
            cur.pop_back();   k.second++;
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        
        for(auto i:nums)
            mp[i]++;
        calc(0,nums.size());
        return (int)ans.size();
    }
};