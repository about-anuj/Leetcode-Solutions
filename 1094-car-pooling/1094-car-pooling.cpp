class Solution {
public:
    bool carPooling(vector<vector<int>>& trip, int cap) {
        int n=trip.size(),mx=-1;
        vector<int>store(1001,0);
        for(int i=0;i<n;i++)
        {
            store[trip[i][1]]+=trip[i][0];
            store[trip[i][2]]-=trip[i][0];   
        }
       for(int i=0;i<=1000 and cap>=0;i++) 
          cap-=store[i];
        
        return cap>=0;  
    }
   
};