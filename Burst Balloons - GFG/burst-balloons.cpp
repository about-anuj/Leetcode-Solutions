//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
int dp[503][503];
    int solve(vector<int>&nums,int i,int j)
    {
     if(i>=j) return 0;
      if(dp[i][j]!=-1) return dp[i][j];
        
        for(int k=i;k<j;k++)
        {
            dp[i][j]=max(dp[i][j],solve(nums,i,k)+solve(nums,k+1,j)+nums[i-1]*nums[k]*nums[j]);
        }
        return dp[i][j];
    }
    int maxCoins(int N, vector<int> &nums) {
        // code here
        memset(dp,0,sizeof(dp));
         if(nums.size()==1) return nums[0];
        nums.insert(nums.begin(),1);
        nums.push_back(1);
       memset(dp,-1,sizeof(dp));
       return solve(nums,1,nums.size()-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends