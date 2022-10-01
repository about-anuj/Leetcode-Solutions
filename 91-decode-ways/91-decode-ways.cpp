class Solution {
public:
    int dp[105];
    int calc(string &s,int i,int n)
    {
        //completed whole string
        if(i>=n) return dp[i]=1;
        //leading zeroes are not allowed
        if(s[i]=='0') return dp[i]=0;
        if(dp[i]!=-1) return dp[i];
        
        int x=0,y=0;
        if(i<n-1)
        {
          int num=stoi(s.substr(i,2));
          //if i<n-1 then we have two options we can include numbers from 11 to 26
          if(num>0 and num<=26)
              x+=calc(s,i+2,n);
        }
        //we always have one option to include single element
         y+=calc(s,i+1,n);
        return dp[i]=x+y;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return calc(s,0,s.size());
    }
};