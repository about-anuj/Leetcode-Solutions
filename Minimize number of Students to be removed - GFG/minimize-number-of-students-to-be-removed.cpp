//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int arr[], int n) {
        // code here
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(v.size()==0)
            v.push_back(arr[i]);
            else
            {
                int l=lower_bound(begin(v),end(v),arr[i])-begin(v);
                if(l!=v.size())
                 v[l]=arr[i];
                else
                 v.push_back(arr[i]);
            }
        }
        return n-v.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends