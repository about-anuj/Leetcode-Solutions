class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int>f1;
        priority_queue<int>pq;
        int ans=0;
        for(auto i:s)
            f1[i-'a']++;
        
        for(auto i:f1) pq.push(i.second);
        
        
        while(pq.size()>1){
            int t1=pq.top(); pq.pop();
            
           // cout<<t1<<" "<<ans<<" "<<pq.size()<<endl;
            //check that top two elements are equal or not
            if(t1==pq.top()){
                ans++;
                //if updated freq 0 then no need to push
                if(t1-1>0)
                pq.push(t1-1);
            } 
        }
        return ans;
    }
};