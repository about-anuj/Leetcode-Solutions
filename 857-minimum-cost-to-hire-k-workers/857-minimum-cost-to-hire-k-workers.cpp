class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=wage.size();
        double temp=0,ans=DBL_MAX;
        //first store ratio wise
        vector<vector<double>>newlist;
      for(int i=0;i<n;i++)
       {
          newlist.push_back({(double)wage[i]/quality[i],(double)quality[i]});
       }
        
        //sort the list according to the ratio
        sort(begin(newlist),end(newlist));
        
        priority_queue<double>pq;
        for(auto worker:newlist)
        {
            //add the value
           temp+=worker[1];
           pq.push(worker[1]);  //push to p_queue
           if(pq.size()>k)
           {
               //here is the use of p_queue
               //remove the maximum value from the window
               temp-=pq.top();
               pq.pop();
           }
            //if size hits then calculate minimum according to
            //current ratio because we can't underpay any employee 
            //so we can't choose first k-1 workers whose wage ratio is less
           if(pq.size()==k)
               ans=min(ans,worker[0]*temp);
        }
        return ans;
    }
};