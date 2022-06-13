class Solution {
public:
    int findMinDifference(vector<string>& time) {
        map<int,int>mp;
        for(auto i:time)
        {
            int x=60*stoi(i.substr(0,2));
            int y=stoi(i.substr(3,2));
            mp[x+y]++;
            mp[x+y+1440]++;
        }
        
        int mn[(int)mp.size()],j=0;
       for(auto i:mp)
       {
          mn[j++]=i.first;
           if(i.second>1)
               return 0;
       }
        j=INT_MAX;
      for(int i=1;i<mp.size();i++)
      {
          j=min(j,(int)(mn[i]-mn[i-1]));
      }
        return j;
    }
};