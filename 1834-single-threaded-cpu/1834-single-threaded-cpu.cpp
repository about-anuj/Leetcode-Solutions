class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++)
            tasks[i].push_back(i);
        
        sort(begin(tasks),end(tasks));
        vector<int>res;
 priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //min heap
        int i=0,n=tasks.size();
        long long ft=tasks[0][0];
        while(i<n or !pq.empty())
        {
            while(i<n and tasks[i][0]<=ft){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
           }
            
            //if no task left than update time
            if(pq.size()==0){
              ft=tasks[i][0];
            }
            else{
                pair<int,int>p=pq.top();
                pq.pop();
                res.push_back(p.second);
                ft+=p.first;
            }
           
        }
      return res;
    }
};