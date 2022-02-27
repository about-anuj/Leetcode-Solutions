class Solution {
public:
    long long bs(vector<int>&v, long long time){
       long long ans=0;
        for(auto i:v){
            long long val=i;
            
            ans+=(time/val);
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long l=1,r=1e14;
        while(l<r){
            long long mid=(l+r)/2;
            
            if(bs(time,mid)>=totalTrips)
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};