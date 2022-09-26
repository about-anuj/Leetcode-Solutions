static bool found=false;
class Solution {
public:
    unordered_map<char,vector<char>>g;
    
    void dfs(char st,vector<int>&vis,char tgt)
    {
        if(vis[st-'a'] or found) return;
        vis[st-'a']=1;
        if(st==tgt)
        {
            found=true;
            return;
        }
        for(auto i:g[st])
        {
            if(!vis[i-'a'])
                dfs(i,vis,tgt);
        }
    }
    bool equationsPossible(vector<string>& eq) {
        int vis[26]={0};
        
        for(auto i:eq)
        {
            //if sign is == then we have to add both character into same graph
            //else they will not be part of each other
                if(i.substr(1,2)=="==")
                {
                   g[i[0]].push_back(i[3]);
                   g[i[3]].push_back(i[0]);
                     vis[i[0]-'a']=1;
                     vis[i[3]-'a']=1;
                }
               
        }
      
        for(auto i:eq)
        {
            vector<int>v(26,0);
                found=false;
                dfs(i[0],v,i[3]);
            // if sign is == then found should be true because both are supposed to part of same graph
                if(i.substr(1,2)=="==" and !found)
                    return 0;
                else if(i.substr(1,2)=="!=" and found) 
                    return 0;
        }
        return 1;
    }
};