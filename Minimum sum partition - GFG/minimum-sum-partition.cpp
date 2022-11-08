//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  vector<vector<int>>dp;
  int calc(int *arr,int i,int n,int s1,int s2)
  {
      if(i==n) return abs(s1-s2);
    //   cout<<s1<<" "<<s2<<endl;
    //   if(i>=n) return 0;
      if(dp[i][s2]!=-1) 
      return dp[i][s2];
      
      return dp[i][s2]= min(calc(arr,i+1,n,s1,s2),calc(arr,i+1,n,s1+arr[i],s2-arr[i]));
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    
	    for(int i=0;i<n;i++) sum+=arr[i];
	    dp.resize(n+1,vector<int>(sum+1,-1));
	    return calc(arr,0,n,0,sum);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends