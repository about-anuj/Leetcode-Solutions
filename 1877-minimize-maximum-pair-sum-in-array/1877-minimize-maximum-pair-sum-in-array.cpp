class Solution {
public:
    int minPairSum(vector<int>& nums) {
        priority_queue<int>p1,p2;
        int n=nums.size(),ans=0;
        for(auto i:nums)
        {
            p1.push(i);
            p2.push(-i);
        }
        for(int i=0;i<n/2;i++){
            ans=max(ans,p1.top()+abs(p2.top()));
            p1.pop();
            p2.pop();
        }
        return ans;
    }
};