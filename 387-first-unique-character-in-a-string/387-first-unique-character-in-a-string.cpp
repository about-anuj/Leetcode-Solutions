class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>>mp;
        int ans=INT_MAX;
      for(int i=0;i<s.size();i++)
      {
      	mp[s[i]].first++;
      	mp[s[i]].second=i;
      }
      for(auto i:mp)
      {
      	if(i.second.first==1)
      	{
      		ans=min(ans,i.second.second);
      	}
      }
      if(ans==INT_MAX) return -1;
      return ans;
    }
};