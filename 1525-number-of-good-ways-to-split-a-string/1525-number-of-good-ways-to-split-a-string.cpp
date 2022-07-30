class Solution {
public:
    int numSplits(string s) {
        int n=s.size(),ans=0;
        vector<int>pre(n,1),suf(n,1);
//        int pre[n]={1},suf[n]=1;
        unordered_map<char,int>mp;
        mp[s[0]]++;
        for(int i=1;i<n;i++)
            if(!mp.count(s[i]))
                pre[i]=pre[i-1]+1,mp[s[i]]++;
            else
                pre[i]=pre[i-1];
        
        mp.clear();
        mp[s[n-1]]++;
        for(int i=n-2;i>=0;i--)
            if(!mp.count(s[i]))
                suf[i]=suf[i+1]+1,mp[s[i]]++;
            else
                suf[i]=suf[i+1];
        
        //for(auto i:pre) cout<<i<<" ";
        for(int i=0;i<n-1;i++)
            if(pre[i]==suf[i+1])
                ans++;
        
        return ans;
    }
};