class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=1;
        priority_queue<int>pq;
        for(;i<heights.size() ;i++)
        {
            if(heights[i]<=heights[i-1]) continue;
            
            pq.push(heights[i]-heights[i-1]);
            bricks-=(heights[i]-heights[i-1]);
            
            if(bricks<0){
                bricks+=pq.top();
                pq.pop();
                ladders--;
            }
            
            if(ladders<0)
              return i-1;
            }
        return i-1;
    }
};