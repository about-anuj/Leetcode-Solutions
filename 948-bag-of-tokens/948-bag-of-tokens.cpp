class Solution {
public:
//     int dp[1002][1002];
//     int calc(vector<int>&token,int i,int n,int p,int s)
//     {
//         if(p<0 or s<0) return 0;
//         if(i==n) return dp[i][s]=1;
        
//         int a=0,b=0;
        
//         if(dp[i][p]!=-1) return dp[i][p];
        
//         for(int j=i;j<n;j++)
//         {
//             if(s>0)
//            a= max(calc(token,j+1,n,p-token[j],s+1)+1,calc(token,j+1,n,p+token[j],s-1)-1);
//         else 
//             b= 1+calc(token,j+1,n,p-token[j],s+1);
//         }
//         return dp[i][s]=max(a,b);
//     }
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // memset(dp,-1,sizeof(dp));
        // // if(tokens.size()==0) return 0;
        // return calc(tokens,0,tokens.size(),power,0);
        sort(begin(tokens),end(tokens));
        int i=0,j=tokens.size()-1,s=0,res=0;
        while(i<=j and (s>0 or power>=tokens[i]))
        {
            if(power>=tokens[i])
            {
                s++;
                power-=tokens[i++];
            }
            else if(s>0)
            {
                s--;
                power+=tokens[j--];
            }
            // cout<<s<<" "<<power<<endl;
            res=max(res,s);
        }
        return res;
    }
};