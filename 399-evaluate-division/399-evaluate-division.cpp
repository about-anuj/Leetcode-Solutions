#define pb push_back
class Solution {
public:
     unordered_map<string,vector<pair<string,double>>>g;
     vector<double>ans;
    unordered_map<string,bool>vis,prsnt;
    
    double dfs(string st, string end, unordered_set<string>vis)
    {
        if(g.find(st)==g.end() or g.find(end)==g.end()) return -1.0;
        if(st==end) return 1.0;
        vis.insert(st);
        for(auto i:g[st])
        {
            if(vis.find(i.first)==vis.end())
            {
                double x=dfs(i.first,end,vis);
                if(x!=-1.0)
                    return x*i.second;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& qr)
    {
        make_graph(eq,val);
        int q=qr.size();
       
        for(int i=0;i<q;i++)
        {
         unordered_set<string>vis;
            ans.pb(dfs(qr[i][0],qr[i][1],vis));
        }
        return ans;
    }
    private:
    void make_graph(vector<vector<string>>&eq,vector<double>&val)
    {
        int j=0;
        for(auto i:eq)
        {
            prsnt[i[0]]=true;
            prsnt[i[1]]=true;
            double x=val[j++];
            g[i[0]].pb({i[1],x});
            g[i[1]].pb({i[0],(1/x)});
        }
    }
};