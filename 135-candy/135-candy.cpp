class Solution {
public:
    int candy(vector<int>& ratings) {
        int j=0,ans=0,n=ratings.size();
       vector<int>l2r(ratings.size(),1),r2l(n,1);
       priority_queue<pair<int,int>>pq;
        
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                l2r[i]=l2r[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
            if(ratings[i]>ratings[i+1])
                r2l[i]=r2l[i+1]+1;
        
        for(int i=0;i<n;i++)
            ans+=max(r2l[i],l2r[i]);
        return ans;
    }
};