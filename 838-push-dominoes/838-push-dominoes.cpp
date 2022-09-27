class Solution {
public:
    string pushDominoes(string s) {
     int n = s.length();
        vector<int> l(n, 0), r(n, 0);
        char prev = '.';
        int count = 1;
        for(int i=0; i<n; i++){
            if(s[i] == 'R'){
                prev = 'R';
                count = 1;
                continue;
            }
            else if(s[i] == 'L') prev = 'L';
            if(prev == 'R' && s[i] == '.') r[i] = count++;
        }
        prev = '.';
        count = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'L'){
                prev = 'L';
                count = 1;
                continue;
            }
            else if(s[i] == 'R') prev = 'R';
            if(prev == 'L' && s[i] == '.') l[i] = count++;
        }
       // for(auto i:l) cout<<i; 
      for(int i=0;i<s.size();i++)
      {
          if(s[i]=='.' and r[i]!=l[i])
          {
             if(max(r[i],l[i])==0) s[i]='.';
             else if(r[i]==0 or l[i]==0) 
             {
               if(r[i]!=0) s[i]='R';
               else s[i]='L';
             }
             else
             {
                 if(r[i]<l[i]) s[i]='R';
                 else s[i]='L';
             }
          }
      }
        return s;
    }
};