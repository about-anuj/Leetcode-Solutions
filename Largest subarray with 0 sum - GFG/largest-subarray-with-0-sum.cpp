// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        // Your code here
        int cur=0,maxlen=0;
        unordered_map<int,int>mp;   //sum,index
        
        for(int i=0;i<nums.size();i++){
            cur+=nums[i];
            
            if(nums[i]==0 and maxlen==0)
            maxlen=1;
            if(cur==0)
            maxlen=i+1;
            
            if(!mp.count(cur))
            mp[cur]=i;
            
            if(mp.count(cur)){
                maxlen=max(i-mp[cur],maxlen);
            }
        }
        return maxlen;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends