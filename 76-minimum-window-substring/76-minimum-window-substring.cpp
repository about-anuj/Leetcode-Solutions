class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp,mp1;
        unordered_set<char>st;
        string ans="";
        for(auto i:t) mp[i]++;
            int i=0,j=0,sz=INT_MAX;
        while(j<=s.size())
        {
            bool cantake=true;
          for(char c='A';c<='z';c++)
              if(mp.count(c) and mp1[c]<mp[c])
                  cantake=false;
            
          //cout<<i<<" "<<j<<endl;
          if(cantake)
          {
              //cout<<j-i+1<<" ";
              if(sz>j-i)
              {
                  ans=s.substr(i,j-i);
                  sz=j-i;
              }
              if(mp.count(s[i]))
                  mp1[s[i]]--;
              i++;
          }
          else
          {
              if(j<s.length() and mp.count(s[j]))
              {
                  mp1[s[j]]++;
              }
              j++;
          }
        }
        return ans;
    }
};