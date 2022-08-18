class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int>pq;
        int n=(arr.size())/2,ans=0;
        unordered_map<int,int>mp;
        for(auto i:arr) mp[i]++;
        for(auto i:mp) pq.push(i.second);
        
        while(n>0)
        {
            n-=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};