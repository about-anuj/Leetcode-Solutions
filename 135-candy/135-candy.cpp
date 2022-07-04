class Solution {
public:
    int candy(vector<int>& ratings) {
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        int ans=0,n=ratings.size();
        
        vector<int>candy(n,-1);
        for(auto i:ratings)
            pq.push({i,ans++});
        ans=0;
        while(!pq.empty()){
            int ind=pq.top().second;
            int val=pq.top().first;
            pq.pop();
            
            int mx=1;
            if(ind>0 and ratings[ind]>ratings[ind-1])
                mx=max(mx,candy[ind-1]+1);
            if(ind<n-1 and ratings[ind]>ratings[ind+1])
                mx=max(mx,candy[ind+1]+1);
            
            candy[ind]=mx;
            ans+=mx;
        }
        return ans;
    }
};