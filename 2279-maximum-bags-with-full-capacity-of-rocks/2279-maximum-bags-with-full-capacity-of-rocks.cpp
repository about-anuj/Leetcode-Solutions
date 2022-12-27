class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& r, int add) {
        int ans=0;
        priority_queue<int>pq;
        for(int i=0;i<cap.size();i++)
        {
            if(cap[i]>r[i])
           pq.push(-1*(cap[i]-r[i]));
            else ans++;
        }
        while(!pq.empty()){
            int val=abs(pq.top());
            pq.pop();
            if(add>=val)
            {
                add-=val;
                ans++;
            }
            else
                break;
        }
        return ans;
    }
};