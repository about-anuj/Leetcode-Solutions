//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        // code here
        unordered_map<int,int>st,after;
        int res=0;
        for(auto i=0;i<N;i++) 
        st[arr[i]%K]++;
        
        for(int i=1,j=K-1;i<=j;i++,j--)
        {
             //take mid element one time
            if(i==j and st.count(i))
            {
            res++;
            break;
            }
            res+=max(st[i],st[K-i]);
            
        }
        //take that element one time
        if(st[0]>0) res++;
        
    
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends