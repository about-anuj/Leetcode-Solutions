class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1 and k%2!=0) return -1;
        //we have only one chance and we only can extract top element that is nums[0]
        if(k==1)
            return nums[1];
        //no choice just return nums[0]
        if(k==0)
            return  nums[0];
        
        //if k>n it means return max element
         if(k>n)
             return *max_element(begin(nums),end(nums));
        
        int mx,mn=-1;
        //dont use priority queue bcz we can find max element in o(k)
       // priority_queue<int>pq;
        for(int i=0;i<k-1;i++) mn=max(mn,nums[i]);
        
        mx=max(mn,nums[k]);
        return mx;
    }
};