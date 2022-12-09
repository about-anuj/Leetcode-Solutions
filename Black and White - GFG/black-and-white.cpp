//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m)
{
    // write code here
    long long res=0,mod=1e9+7;
    for(int i=0;i<n;i++)
    {
        
        // cout<<i<<" ";
        for(int j=0;j<m;j++)
        {
            int cant=0;
            if(i-2>=0 and j-1>=0) { cant--;}
            if(i-1>=0 and j-2>=0) { cant--;}
            if(i-2>=0 and j+1<m) { cant--;}
            if(i-1>=0 and j+2<m) { cant--;}
            if(i+1<n and j+2<m) { cant--;}
            if(i+2<n and j+1<m) { cant--;}
            if(i+1<n and j-2>=0) { cant--;}
            if(i+2<n and j-1>=0) { cant--;} 
            // cout<<cant<<" ";
            res=(res+m*n+cant-1)%mod;  //one position is already occupied by the current knight
        }
        // cout<<endl;
        // cout<<cant<<" ";
       
    }
    return res;
}