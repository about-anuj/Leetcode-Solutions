//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    stack<char>st;
    for(auto i:num)
    {
        while(st.size() and st.top()>i and k>0)
           st.pop(),--k;
            
        st.push(i);
    }
    while(k--)
        st.pop();
        
    num.erase();
    while(st.size())
    {
        num.push_back(st.top());
        st.pop();
    }
    reverse(begin(num),end(num));
    int i=0;
    while(i<num.size() and num[i]=='0') i++;
    return i>=num.size()?"0":num.substr(i);
}