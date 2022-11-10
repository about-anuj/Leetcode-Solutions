//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   long long res=0;
    void calc(int st,long long x)
    {
        queue<long long>q;
        q.push((long long)st);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                long long f=q.front(); q.pop();
                if(f>x) continue;
                int rem=f%10;
                res=max(res,f);
                if(rem==0)
                {
                    q.push(f*10+rem+1);
                }
                else if(rem==9)
                {
                    q.push(f*10+rem-1);
                }
                else
                {
                    q.push(f*10+rem+1);
                    q.push(f*10+rem-1);
                }
            }
        }
    }
    long long jumpingNums(long long x) {
        // code here
        for(int i=1;i<10;i++)
        {
            calc(i,x);
        }
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends