class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long long>dp(5,1),temp(5,0);
        int mod=1e9+7;
       // unordered_map<int,long long>mp;
       // for(int i=0;i<5;i++) mp[i]=1;
        for(int i=0;i<n-1;i++)
        {
                temp[0]=(dp[2]+dp[1]+dp[4])%mod;     //e,i,u
                temp[1]=(dp[0]+dp[2])%mod;                    //i,a
                temp[2]=(dp[1]+dp[3])%mod;                      //o,e
                temp[3]=(dp[2])%mod;                    //i
                temp[4]=(dp[2]+dp[3])%mod;                      //o,i
            
              dp=temp;
        }
        long long sum=0;
        for(int i=0;i<5;i++) sum+=dp[i];
        return sum%mod;
    }
};