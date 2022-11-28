//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	     vector<int> ans;

     vector<int> store;

     int sum = 0;

     int ansSum = 0;

     for(int i = 0; i <= n; i++){

         if(i == n or a[i] < 0){

             if(ansSum < sum){ 

                 ansSum = sum;

                 ans = store;

             }

             sum = 0;

             store.clear();

             continue;

         }

         sum += a[i];

         store.push_back(a[i]);

     }

     

     if(ans.size() == 0) return {-1};

     return ans;    
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends