class Solution {
public:
    int candy(vector<int>& ratings) {
        int j=0,ans=0,n=ratings.size();
       vector<int>l2r(ratings.size(),1);
       priority_queue<pair<int,int>>pq;
        
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                l2r[i]=l2r[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
            if(ratings[i]>ratings[i+1])
                l2r[i]=max(l2r[i],l2r[i+1]+1);
        
        
        return accumulate(begin(l2r),end(l2r),0);
    }
};