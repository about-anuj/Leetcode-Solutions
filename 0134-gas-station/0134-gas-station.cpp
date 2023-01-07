class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 1 2 3 4 5
        // 3 4 5 1 2
        // 1 0 -1 -2 2
        
        // 2 3 4 
        // 3 4 3
        // 2 2 2
        int gt=accumulate(begin(gas),end(gas),0);
        int ct=accumulate(begin(cost),end(cost),0);
        if(gt<ct) return -1;
        int cur=0,n=gas.size(),res=0;
        for(int i=0;i<n;i++)
        {
          if(cur<0)
          {
              res=i;
              cur=0;
          }
         cur+=gas[i]-cost[i];
        }
       return res;
    }
};