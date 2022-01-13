class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points),end(points));
        vector<vector<int>>v;
        v.push_back(points[0]);
        int x1=0,x2=0;
        for(int i=1;i<points.size();i++)
        {
            vector<int>x=v.back();
            if(x[1]>=points[i][0])
            {
                v.pop_back();
                v.push_back({max(x[0],points[i][0]),min(x[1],points[i][1])});
            }
            else{
                v.push_back(points[i]);
             //  cout<<v.size()<<" ";
            }
        }
        return (int)v.size();
    }
};