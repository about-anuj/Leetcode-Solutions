class Solution {
public:
//      long long dp[1001][1001];
    
//     int calc(vector<int>&nums,int k,int i,int n){
//         if(i>=n-1){
//             return nums.back();
//         }
        
//        int ans=INT_MIN;
//         for(int j=1;j<=k;j++)
//             ans=max(ans,nums[i]+calc(nums,k,i+j,n));
        
//         return ans;
//     }
    int maxResult(vector<int>& nums, int k) {
        // memset(dp,-1,sizeof(dp));
        // return (int)calc(nums,k,0,nums.size());
        vector<int>dp(size(nums),INT_MIN);
        priority_queue<pair<int,int>>pq;
        pq.push({nums[0],0});
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
           while(i-pq.top().second>k)
               pq.pop();
            
            dp[i]=nums[i]+pq.top().first;
            pq.push({dp[i],i});
        }
       // for(auto i:dp) cout<<i<<" ";
       return dp.back();
    }
    
};