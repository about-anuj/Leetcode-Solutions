#define pb push_back
class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()<=1) return 0;
        
        unordered_map<int,vector<int>>mp,g;
         int ans=0,n=arr.size();
            vector<bool>vis(arr.size(),false);
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].pb(i);
        }
    
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0]=true;
        while(!q.empty())
        {
            int x=q.front().first;
            int d=q.front().second;
            q.pop();
            
            if(x==n-1) return d;
            else
            {
                if(x>0 and !vis[x-1])
                {
                 vis[x-1]=true;
                 q.push({x-1,d+1});
                }
                if(x+1<n and !vis[x+1])
                {
                    vis[x+1]=true;
                    q.push({x+1,d+1});
                }
                for(auto i:mp[arr[x]])
                {
                    if(!vis[i])
                    {
                        vis[i]=true;
                        q.push({i,d+1});
                    }
                }
                mp[arr[x]]={};
            }
           
        }
       
        return -1;
    }
};