class Solution {
public:
    unordered_map<int,vector<string>>mp;
    map<pair<int,string>,int>dp;
    bool ispre(string a , string b)
    {
        int diff=0;
        for(int i=0,j=0;i<a.size() and j<b.size();)
        {
            if(a[i]==b[j])
                i++,j++;
            else{
                diff++;
                j++;
            }
        }
        return diff<2;
    }
    
    int calc(int i, string cur)
    {
        if(!mp.count(i)) 
            return 0;
        
        int mxlen=0;
        if(dp.count({i,cur})) 
            return dp[{i,cur}];
        
        for(auto j:mp[i])
        {
            if(ispre(cur,j))
                mxlen=max(mxlen,1+calc(i+1,j));
        }
        return dp[{i,cur}]=mxlen;
    }
    
    
    int longestStrChain(vector<string>& words) {
        
        int ans=1;
     for(auto i:words)
        mp[(int)i.size()].push_back(i);
        
      for(int i=1;i<17;i++)
          ans=max(ans,calc(i,""));
        
        return ans;
    }
};