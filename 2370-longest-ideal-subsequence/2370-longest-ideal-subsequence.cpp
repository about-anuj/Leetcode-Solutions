class Solution {
public:
  // int dp[100002][150];
    
    //map<pair<char,int>,int>mp;
    int calc(string &s,int &k,int i,int n,char cur,vector<vector<int>>&dp)
    {
        if(i>=n)
            return 0;
        
     
        int x=0;
        if(dp[i][cur]!=-1) return dp[i][cur];
       
        if(cur=='#' or abs(cur-s[i])<=k)
            x=1+calc(s,k,i+1,n,s[i],dp);
        //else
           int y=calc(s,k,i+1,n,cur,dp);
        
        return dp[i][cur]=max(x,y);
    }
    int longestIdealString(string s, int k) { 
        vector<vector<int>>dp(s.length()+1,vector<int>(150,-1));
        //memset(dp,-1,sizeof(dp));
        return calc(s,k,0,s.size(),'#',dp);
    }
};
// int helper_function(String s,int k,int idx,char ch,int dp[][]){
//         if(idx==s.length()) return 0;
//         if(dp[idx][ch]!=-1) return dp[idx][ch];
//         int pick=0;
//              if(Math.abs(ch-s.charAt(idx))<=k || ch=='#') pick=1+helper_function(s,k,idx+1,s.charAt(idx),dp);
//             int notpick=helper_function(s,k,idx+1,ch,dp);
//        return dp[idx][ch]=Math.max(pick,notpick);
        
//     }
//     public int longestIdealString(String s, int k) {
//         int n=s.length();
//         int dp[][]=new int[n+1][150];
//         for(int sub_array[]:dp)
//          Arrays.fill(sub_array,-1);
//         return helper_function(s,k,0,'#',dp);
        
//     }