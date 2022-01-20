class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int l=1;
     int r=1e+9;
     int ans=INT_MAX;
     while(l<=r)
     {
         //cout<<l<<" "<<r<<endl;
        int mid=(l+r)/2;
        int t=0;
        for(auto i:p)
        {
            t+=i/mid;
            if(i%mid!=0) 
              t++;
        }
        if(t<=h){
            r=mid-1;
         ans=min(ans,mid);
        }
         else 
             l=mid+1;

     }
     return ans;
    }
};