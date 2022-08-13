class Solution {
public:
     //s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
     bool calc(unordered_map<string,int>st,string s,int subsz)
     {
      for(int i=0;i<s.size();i+=subsz)
      {
         string substr=s.substr(i,subsz);
         if(st[substr]==0) return false;
         st[substr]--;
      }
      return true;
     }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>st;
        vector<int>ans;
        int ssz=s.size(),wordssz=words[0].size()*words.size();
        if(ssz<wordssz) 
        return {};
        
        for(auto i:words) 
        st[i]++;

        for(int i=0;i<=ssz-wordssz;i++)
        {
          if(calc(st,s.substr(i,wordssz),words[0].size()))
          ans.push_back(i);
        }
        return ans;
    }
};