class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        long long ans=0,cur=1;
        nums.push_back(INT_MAX);
        sort(begin(nums),end(nums));
        
        for(int i=0;k>0 and i<nums.size();i++){
            int take=max(0,min(k,nums[i]-(int)cur));
            
            ans+=((cur+take)*(cur+take-1))/2-(cur*(cur-1))/2;
            
            k-=take;
            cur=(long long)nums[i]+1;
        }
        return ans;
    }
};