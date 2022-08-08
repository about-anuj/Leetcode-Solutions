class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int k=nums.size();
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
	    for(int i = 0; i <= k; i++) {
		    //ans[i] = new int[k+1];
		    for(int j = 0; j <= k; j++) {
		    	dp[i][j] = -1;
		    }
	    }
        return lis(-1,0,nums,dp);
    }
    int lis(int prev,int curr,vector<int>& arr,vector<vector<int>>&dp){
        if(curr==arr.size()){
            return 0;
        } 
        if(prev!=-1 && dp[prev][curr]!=-1){
            return dp[prev][curr];
        }
        int first=0;
        if(prev==-1 || arr[prev]<arr[curr]){
            first=1+lis(curr,curr+1,arr,dp);
        }
        int sec=lis(prev,curr+1,arr,dp);
        if(prev!=-1){
            return dp[prev][curr]=max(first,sec);
        }else
            return max(first,sec);
    }
};