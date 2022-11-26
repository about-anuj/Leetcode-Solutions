class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& en, vector<int>& pr) {
      int n=*max_element(begin(en),end(en));
      vector<pair<int,pair<int,int>>>v;
      for(int i=0;i<en.size();i++) 
          v.push_back({en[i],{st[i],pr[i]}});
        
      sort(begin(v),end(v));
       
      map<int,int>dp={{0,0}};
      int j=0,res=0;
        for(int i=0;i<en.size();i++)
        {
                int start=v[i].second.first;
                int end=v[i].first;
                int profit=v[i].second.second;
                int vs=prev(dp.upper_bound(start))->first;
                dp[end]=max(dp.rbegin()->second,profit+dp[vs]);
            
                res=max(res,dp[end]);
                cout<<res<<" ";
          }
        return res;
    }
};