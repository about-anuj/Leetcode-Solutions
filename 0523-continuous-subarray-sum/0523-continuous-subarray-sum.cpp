class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=-1;
        for(auto i=0;i<nums.size();i++)
        {
            // sum=(sum+nums[i])%k;
            sum+=nums[i];
            sum%=k;
            if(mp.count(sum) and i-mp[sum]>=2) return true;
            else if(mp.count(sum)==0)  mp[sum]=i;
            
        }
        return 0;
    }
};