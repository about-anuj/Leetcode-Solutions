class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        string ans="";
        int mx=INT_MIN;
        for(auto i:s)
        {
            mp[i]++;
            mx=max(mx,mp[i]);
        }
        if(mx>(n+1)/2) return "";
       priority_queue<pair<int,char>>pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        int i=0;
        pair<int,int>prev=pq.top(); pq.pop();
        ans+=prev.second;
       // prev.first--;
        while(!pq.empty())
        {
            pair<int,char>curr=pq.top();
            pq.pop();
            int x=curr.first;
            char val=curr.second;
            ans+=val;
            if(prev.first-1>0)pq.push({prev.first-1,prev.second});
            prev={x,val};
        }
        return ans;
    }
};