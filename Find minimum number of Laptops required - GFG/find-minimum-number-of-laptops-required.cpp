//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int n, int st[], int end[]) {
        // Code here
        sort(st,st+n);
        sort(end,end+n);
        int res=0,i=0,j=0,cnt=0;
        while(i<n and j<n)
        {
            if(st[i]<end[j])
            {
                cnt++;
                res=max(res,cnt);
                i++;
            }
            else
            {
                j++;
                cnt--;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends