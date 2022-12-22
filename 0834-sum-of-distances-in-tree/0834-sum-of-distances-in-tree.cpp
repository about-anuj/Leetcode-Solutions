#define pb push_back
class Solution {
public:
    vector<int>cnt,ans; //cnt,ans
    unordered_map<int,vector<int>>g;
    int total;
    //no need to make vis as there is only one edge
    void f1(int src,int par)
    {
        for(auto c:g[src])
        {
            if(c!=par) {
            f1(c,src);
            cnt[src]+=cnt[c];
            ans[src]+=ans[c]+cnt[c];
            }
        }
    }
    void f2(int src,int par)
    {
        for(auto c:g[src])
        {
            if(c!=par) 
            {
            ans[c]+=(ans[src]+(total-cnt[c])-ans[c]-cnt[c]);
            f2(c,src);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        cnt.resize(n,1);
        ans.resize(n,0);
        total=n;
        //make graph
        for(auto i:edges)
        {
            g[i[0]].pb(i[1]);
            g[i[1]].pb(i[0]);
        }
        
        
        //find cnt and ans just for subtree upper tree calculation will be in next function.
        f1(0,-1);
        //to calc ans for upper subtree als0
        f2(0,-1);
        return ans;
    }
};