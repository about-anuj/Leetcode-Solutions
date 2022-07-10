class Solution {
public:
    int dp[1002];
    
    int calc(vector<int>& arr, int d,int i)
    {
        
        if(dp[i]!=-1)
            return dp[i];
        int ans=1;
        // jump in back direction
        for(int j=i-1;j>=max(0,i-d) and arr[i]>arr[j];j--){
            //cant jump on same index
                ans=max(ans,1+calc(arr,d,j));
        }
        for(int j=i+1;j<=min(i+d,(int)arr.size()-1) and arr[i]>arr[j];j++){
            //cant jump on same index
            ans=max(ans,1+calc(arr,d,j));
        }
        return dp[i]=ans;
		// for(int j=i+1; j<=min(i+d, n-1) and arr[i] > arr[j]; ++j) ans = max(ans, 1 + f(arr, d, j, n));
		// //left
		// for(int j=i-1; j>=max(i-d, 0) and arr[i] > arr[j]; --j) ans = max(ans, 1 + f(arr, d, j, n));
		// return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int x=calc(arr,d,i);
            ans=max(ans,x);
        }
        return ans;
    }
};