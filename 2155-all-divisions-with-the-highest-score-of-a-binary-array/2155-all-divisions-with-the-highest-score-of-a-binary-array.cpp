class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n+1,0),suff(n+1,0);
        for(int i=1;i<n+1;i++)
          {
           if(nums[i-1]==0)
               pre[i]=pre[i-1]+1;
           else
               pre[i]=pre[i-1];
           // cout<<pre[i]<<" ";
           }
    for(int i=n-1;i>=0;i--)
    {
        if(nums[i]==1)
            suff[i]=suff[i+1]+1;
        else
            suff[i]=suff[i+1];
       
    }
       
        vector<pair<int,int>>v;
        for(int i=0;i<=n;i++)
        {
            v.push_back({pre[i]+suff[i],i});
        }
        sort(begin(v),end(v));
       // reverse(begin(v),end(v));
        int i=n,x=v[n].first;
        vector<int>ans;
        while(i>=0 and v[i].first==x)
        {
            ans.push_back(v[i].second);
            //cout<<v[i].first<<" ";
            i--;
        }
        //sort(begin(ans),end(ans));
        return ans;
    }
};