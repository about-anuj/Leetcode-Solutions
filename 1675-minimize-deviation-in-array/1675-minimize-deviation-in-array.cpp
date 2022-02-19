class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
       //declare min and max element 
       // to check minimum difference
        int mx=INT_MIN,mn=INT_MAX;
        //to store maximum element later
        priority_queue<int>pq;
        
        for(int i=0;i<nums.size();i++)
        {
            //maximize all elements
            if(nums[i]%2!=0)
           nums[i]*=2;
            
           mx=max(mx,nums[i]);
           mn=min(mn,nums[i]);
        }
        
        //push all maximize elements in the priority_queue
        for(int i:nums) pq.push(i);
        
        int diff=mx-mn;
        //while we find even element as greatest element
        //we try to minimize difference as by dividing it by 2
        while(pq.top()%2==0)
        {
           int top=pq.top();
            pq.pop();
            
            //top is maximum so see difference
            //if less then store in diff
            diff=min(diff,top-mn);
            
            //divide top/2
            top/=2;
            //if top/2 is less then min then store it
            mn=min(mn,top);
            pq.push(top);
        }
        diff=min(diff,pq.top()-mn);
        return diff;
    }
};