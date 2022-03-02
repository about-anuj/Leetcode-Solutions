class Solution {
public:
    bool check(string t, string s){
        int i=0,j=0;
        while(i<s.size() and j<t.size())
        {
            if(s[i]==t[j]){
                i++,j++;
            }
            else
                j++;
            
            if(i==s.size())
                return true;
        }
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        unordered_map<string,int>mp;
        for(auto t:words)
            mp[t]++;
        
        
        for(auto i:mp)
            if(check(s,i.first))
                ans+=i.second;
         
        return ans;
    }
};