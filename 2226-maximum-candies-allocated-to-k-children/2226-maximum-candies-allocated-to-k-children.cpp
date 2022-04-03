class Solution {
public:
    int maximumCandies(vector<int>& c, long long k) {
        long long total=accumulate(begin(c),end(c),0LL);
        
        if(total<k) return 0;
        
        cout<<total;
        if(total==k) return 1;
        int ans=0;
        long long l=1,r=total;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            long long t=0;
            for(auto i:c)
            {
                if(mid==0) break;
                
               // if(i>=mid)
                    t+=i/mid;
            }
            if(t>=k){
                ans=max(ans,(int)mid);
                l=mid+1;
            }
            else
                r=mid-1;
            
           // if(t==k) ans;
        }
        return ans;
    }
};