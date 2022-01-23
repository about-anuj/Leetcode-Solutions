class Solution {
public:
    string s;
    int ans,n;
    //vector<vector<int>>v;
    bool valid(vector<vector<int>>&v)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                for(int j=0;j<n;j++)
                {
                    if(v[i][j]!=2 and v[i][j]!=s[j]-'0')
                        return 0;
                }
            }
        }
        return 1;
    }
    void dfs(vector<vector<int>>&v, int i,int n,int count)
    {
        
        if(i==n){
            if(valid(v))
                ans=max(ans,count);
            return;
        }
         s.append(1,'0');
         dfs(v,i+1,n,count);
         s.back()='1';
         dfs(v,i+1,n,count+1);
         s.pop_back();
    }
    int maximumGood(vector<vector<int>>& st) {
         n=st.size();
         ans=0;
         s.reserve(n);
         dfs(st,0,n,0);
         return ans;
    }
   
   
};