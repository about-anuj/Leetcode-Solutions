class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        ///calculate total cost and total gas
      int tc=accumulate(begin(c),end(c),0);
      int tg=accumulate(begin(g),end(g),0);
        //if total gas is less then total cost
        if(tg<tc) return -1;
        
      //now one ans will exist for sure
        int tank=0,ans=0;
        for(int i=0;i<g.size();i++)
        {
          if(tank<0)
            {
                ans=i;
                tank=0;
            }
            tank=tank-c[i]+g[i];
        }
        return ans;
    }
};