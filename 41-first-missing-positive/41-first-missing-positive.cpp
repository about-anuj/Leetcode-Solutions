class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=(int)nums.size(),c=0,mn=INT_MAX;
//         //c will measure number of non [positive] integers including 0
//         for(auto i:nums){
//             if(i<=0)
//                 c++;
//             else
//                 mn=min(mn,i);
//         }
//         if(mn!=1)
//             return 1;
        
//         //now answer will be from 1 to n-c;
        
        unordered_map<int,int>mp;
        for(auto i:nums)
            mp[i]++;
        
        for(int i=1;i<=n+1;i++)
            if(!mp.count(i))
                return i;
        
        return 0;
    }
};