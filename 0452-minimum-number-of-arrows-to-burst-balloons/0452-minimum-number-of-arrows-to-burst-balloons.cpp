class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points),end(points));
        int res=0,n=points.size();
        pair<int,int>p={INT_MIN,INT_MAX};   //denotes st and end of available butrst points
        for(int i=0;i<n;i++)
        {
          if(points[i][0]<=p.second)
          {
              p.first=max(p.first,points[i][0]);
              p.second=min(p.second,points[i][1]);
          }
          else
          {
              p={points[i][0],points[i][1]};
              res++;
          }
        }
        return res+1;  //at first we didnt provided any burstpoints
    }
};