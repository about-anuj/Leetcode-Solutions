//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int n){
      //Code here
      int i=0,j=0;
      long long res=0;
      while(i<n)
      {
          if(arr[j]<=0)
          {
              while(i<n and arr[j]<0)
              {
                  if(arr[i]>0)
                  {
                      int dif=min(abs(arr[i]),abs(arr[j]));
                      res+=dif*abs(i-j);
                      arr[j]+=dif;
                      arr[i]-=dif;
                  }
                  while(i<n and arr[i]<=0)
                  i++;
              }
          }
          j++;
      }
      return res;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends