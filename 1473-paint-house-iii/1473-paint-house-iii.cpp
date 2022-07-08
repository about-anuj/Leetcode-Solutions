class Solution {
public:
    long long dp[200][200][200];
    bool setted=false;
    //vector<int>& houses,ll index,vector<vector<int>>& cost,ll prev,ll m,ll n,ll target
    long long calc(vector<int>&h,vector<vector<int>>&cost,int m, int n, int tgt,int ind,int prev){
       //if there are no more neighbours
        if(tgt<0)
            return INT_MAX;
        
        if(m==ind)
        {
            if(tgt==0)
                return 0;
            return INT_MAX;
        }
        if(dp[ind][prev][tgt]!=-1)
            return dp[ind][prev][tgt];
        
        //if house is already painted
        if(h[ind]!=0){
            return dp[ind][prev][tgt]=calc(h,cost,m,n,tgt-(prev!=h[ind]),ind+1,h[ind]);
        }
        
        long long ans=INT_MAX;
        for(int i=1;i<=n;i++){
             ans=min(ans,cost[ind][i-1]+calc(h,cost,m,n,tgt-(prev!=i),ind+1,i));
        }
        return dp[ind][prev][tgt]=ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
       
        //to set dp
        //if(!setted){
          memset(dp,-1,sizeof(dp));
          //setted=true;
        //}
        vector<int>nbr(m,0),cst(m,0);
        int ans=(int)calc(houses,cost,m,n,target,0,0);
        return ans==INT_MAX?-1:ans;
     
    }
};