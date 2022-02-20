class Solution {
public:
    //if first element is less then it is ok to sort
    //but if first element is equal then sort on the
    //basis of gap or put larger range vector first
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //sort the intervals on the basis of cpmprator
        sort(begin(intervals),end(intervals),
             [](vector<int>& a, vector<int>& b)
             {
                 return (a[0]==b[0])?(a[1]>b[1]):(a[0]<b[0]); 
             });
        
        int x=intervals[0][0],y=intervals[0][1],ans=1;
        for(int i=1;i<intervals.size();i++)
        {
         
            //if below condition satisfied then it is ok dont push into vector
            //The interval [a, b) is covered by the interval [c, d) if and only if c <= a and 
            //b <= d.
            if(x<=intervals[i][0] and y>=intervals[i][1])
            {
               continue;
            }
            //if above condition not satisfied then push into v
            else
                {
                ans++;
                x=intervals[i][0];
                y=intervals[i][1];
            }
        }
        return ans;
    }
};