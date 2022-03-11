class Solution {
public:
    unordered_map<int,int>mp;
    bool calc(vector<int>&stones, int i, int k, vector<vector<int>>&dp)
    {
        //if reached to front bank
        if(i==stones.size()-1)
            return true;
        
        if(i>=stones.size()) 
          return false;
  	
        if(dp[i][k]!=-1) // if we already encountered this state ,we'll simply return it
          return dp[i][k]; 
    
        bool ans=false;
        for(int j=-1;j<=1;j++)
        {
            int next_step=k+j;
            if(next_step>0)
            {
               if(!mp.count(next_step+stones[i]))
                   continue;
            
                int ind=mp[next_step+stones[i]];
                if(stones[ind]!=stones[i]+next_step)
                    continue;
                
                ans=ans || calc(stones,ind,next_step,dp);
            }
        }
        
        return dp[i][k]=ans;
    }
    bool canCross(vector<int>& stones) {
       int n=stones.size();
        vector<vector<int>>dp(2000,vector<int>(2000,-1));
        //dp[n+1][3];
        for(int i=0;i<n;i++)
            mp[stones[i]]=i;
        
        return calc(stones,0,0,dp);
    }
};