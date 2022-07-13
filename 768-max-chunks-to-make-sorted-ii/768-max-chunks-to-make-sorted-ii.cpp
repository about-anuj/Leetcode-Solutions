class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(),ans=0;
        vector<int>mx(n,0),mn(n,0);
        mx[0]=arr[0];
        mn[n-1]=arr[n-1];
        for(int i=1;i<n;i++)
            mx[i]=max(arr[i],mx[i-1]);
        
        for(int i=n-2;i>=0;i--)
            mn[i]=min(arr[i],mn[i+1]);
        
        for(int i=0;i<n-1;i++){
           // cout<<mx[i]<<" "<<mn[i]<<endl;
            ans+=(mx[i]<=mn[i+1])?1:0;
        }
        return min(ans+1,int(arr.size()));
    }
};