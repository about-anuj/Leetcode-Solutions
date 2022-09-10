class Solution {
public:
    int dp[2001][2001];
    bool calc(vector<int>&stones,unordered_map<int,int>&mp,int curind,int jump,int n)
    {
        if(curind==n-1) return true;
        if(curind>=n) return 0;
        
        if(dp[curind][jump]!=-1) return dp[curind][jump];
        bool ans=false;
        for(int i=-1;i<=1;i++)
        {
            int n_step=jump+i;
if(n_step>0 and mp.count(n_step+stones[curind])>0 and stones[curind]+n_step==stones[mp[n_step+stones[curind]]])
            {
                ans =ans|| calc(stones,mp,mp[n_step+stones[curind]],n_step,n);
            }
        }
        return dp[curind][jump]=ans;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int>mp;
        int j=0;
        memset(dp,-1,sizeof(dp));
        for(auto i=0;i<stones.size();i++) mp[stones[i]]=i;
        return calc(stones,mp,0,0,stones.size());
    }
};

//  bool calc(vector<int>&stones, int i, int k, vector<vector<int>>&dp)
//     {
//         //if reached to front bank
//         if(i==stones.size()-1)
//             return true;
        
//         if(i>=stones.size()) 
//           return false;
  	
//         if(dp[i][k]!=-1) // if we already encountered this state ,we'll simply return it
//           return dp[i][k]; 
    
//         bool ans=false;
//         for(int j=-1;j<=1;j++)
//         {
//             int next_step=k+j;
//             if(next_step>0)
//             {
//                if(!mp.count(next_step+stones[i]))
//                    continue;
            
//                 int ind=mp[next_step+stones[i]];
//                 if(stones[ind]!=stones[i]+next_step)
//                     continue;
                
//                 ans=ans || calc(stones,ind,next_step,dp);
//             }
//         }
        
//         return dp[i][k]=ans;
//     }