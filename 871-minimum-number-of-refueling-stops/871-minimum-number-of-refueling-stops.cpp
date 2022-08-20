class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int curreach=startFuel;
        priority_queue<int>pq;
        int i=0,ans=0;
        while(curreach<target)
        {
        
           while(i<stations.size() and stations[i][0]<=curreach)
           {
              pq.push(stations[i++][1]);
           }
            if(pq.empty()) return -1;
            curreach+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};