class Solution {
public:
    bool carPooling(vector<vector<int>>& trip, int cap) {
        int n=trip.size(),mx=-1;
     
        vector<int>store(1001,0);
        for(int i=0;i<n;i++)
        {
            for(int j=trip[i][1];j<trip[i][2];j++){
                store[j]+=trip[i][0];
                mx=max(mx,store[j]);
            }
        }
     
        return mx<=cap;
    }
};