class Solution {
public:
   
    vector<int>ans;
    
    bool helper( unordered_map<string,int>mp, string cur, int subsize)
    {
       
        for(int j=0;j<cur.size();j+=subsize)
        {
            string temp=cur.substr(j,subsize);
            if(!mp[temp]) return false;
            mp[temp]--;
                
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
         unordered_map<string,int>mp;
         int sz=words.size()*words[0].size();
        
        for(auto i:words) mp[i]++;
        
        if(sz>s.size()) return ans;
        
        for(int i=0;i<=s.size()-sz;i++)
        {
            bool ok=helper(mp,s.substr(i,sz),words[0].size());
            if(ok)
                ans.push_back(i);
        }
        return ans;
    }
};