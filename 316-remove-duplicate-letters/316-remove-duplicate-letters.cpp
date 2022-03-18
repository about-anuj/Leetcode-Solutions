class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
       vector<int>cnt(26,0),vis(26,0);
        string res="";
        for(auto i:s) cnt[i-'a']++;
        
        for(auto i:s)
        {
            cnt[i-'a']--;
            if(vis[i-'a']==0)
            {
                while(res.size()>0 and res.back()>i and cnt[res.back()-'a']>0)
                {
                    vis[res.back()-'a']=0;
                    res.pop_back();
                }
                vis[i-'a']++;
                res+=i;
            }
        }
        return res;
    }
};