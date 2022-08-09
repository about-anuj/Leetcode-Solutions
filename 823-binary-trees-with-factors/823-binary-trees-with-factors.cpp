class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int n=arr.size(),mod=1e9+7;
        unordered_map<int,long long>dp;
        //initial value has one ans only
        dp[arr[0]]=1;
        
        //iterate over the loop
        for(int i=1;i<n;i++)
        {
            dp[arr[i]]=1;
            //iterate on smaller elements
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                long long l=dp[arr[j]],r=dp[arr[i]/arr[j]];
                   //cout<<l<<" "<<r<<endl;
                dp[arr[i]]+=(l*r)%mod;
                dp[arr[i]]%=mod;
                }
            }
            
        }
        int ans=0;
        for(auto i:dp) ans=(ans+i.second)%mod;
        return ans;
    }
};