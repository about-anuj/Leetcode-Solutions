class Solution {
public:
    
    bool equal(string s,string p){
        unordered_map<char,char>mp1,mp2;
        for(int i=0;i<s.size();i++){
            if(mp1.count(p[i]) or mp2.count(s[i])){
               if(mp1[p[i]]!=s[i] or mp2[s[i]]!=p[i])
                return false;
            }
            else{
                mp1[p[i]]=s[i];
                mp2[s[i]]=p[i];
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string>ans;
        for(auto i:words){
            if(equal(i,pattern))
            {
             ans.push_back(i);   
            }
        }
        return ans;
    }
};