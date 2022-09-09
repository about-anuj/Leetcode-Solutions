class Solution {
public:
    bool static cmp(const vector<int> &a,const vector<int> &b)
    {
         if (a[0] == b[0])
          {
               return a[1] > b[1];
          }
          return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(begin(p),end(p),cmp);
        int mx=INT_MIN,ans=0;
        for(int i=p.size()-1;i>=0;i--)
        {
           if(p[i][1]<mx)
               ans++;
            mx=max(mx,p[i][1]);
        }
        return ans;
    }
};