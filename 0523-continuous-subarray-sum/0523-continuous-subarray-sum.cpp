class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
       unordered_map<int,int>mp;
        int sum=0;
        mp[0]=-1;
        for(auto i=0;i<nums.size();i++)
        {
            sum=(sum+nums[i])%k;
            // if(sum==0) return true;
            // (sum+x)%k==0
            
            if(mp.count(sum) and i-mp[sum]>=2) return true;
            else if(mp.count(sum)==0)  mp[sum]=i;
            
        }
        return 0;
    }
};
// runningSum+=nums[i];
            
//             if(k!=0) 
//                 runningSum = runningSum%k;
            
//             //check if the runningsum already exists in the hashmap
//             if(mp.find(runningSum)!=mp.end())
//             {
//                 //if it exists, then the current location minus the previous location must be greater than1
                
//                 if(i-mp[runningSum]>1)
//                     return true;
//             }
//             else
//             {
//                 //otherwise if the current runningSum doesn't exist in the hashmap, then store it as it maybe used later on
                
//                 mp[runningSum]=i;
//             }