class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int i=0;
        while(i<intervals.size() and intervals[i][1]<newInterval[0])
            ans.push_back(intervals[i++]);
        
        while(i<intervals.size() and newInterval[1]>=intervals[i][0])
        {
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i++][1],newInterval[1]);
        }
        ans.push_back(newInterval);
        while(i<intervals.size())
            ans.push_back(intervals[i++]);
        
        return ans;
        
    }
};