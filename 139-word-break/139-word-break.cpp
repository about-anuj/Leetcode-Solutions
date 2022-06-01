class Solution {
public:
    unordered_set<string>st;
    unordered_map<string,bool>dp;
    bool ok=true;
    
    //set into set
    void sets(vector<string>& wrd){
        for(auto i:wrd)
            st.insert(i);
    }
    
    
    bool wordBreak(string s, vector<string>& wrd) {
       if(ok){
          ok=false;
           sets(wrd);
       }
        
        if(st.find(s)!=st.end())
            return true;
        
        if(dp.find(s)!=dp.end()) return dp[s];
        
        for(int i=1;i<=s.length();i++)
         {
           string t=s.substr(0,i);
           auto it=st.find(t)!=st.end(); 
           if(it and wordBreak(s.substr(i),wrd))
               return dp[s]=true;
         }
        return dp[s]=false;
    }
};