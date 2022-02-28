class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        
            
        vector<string>ans;
        if(nums.size()==0) return ans;
       
        for(int i=0;i<nums.size();)
        {
            int j=i;
             while(j<nums.size()-1 and nums[j]+1==nums[j+1]) 
                 j++;
                    
            if(j>i)
             ans.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
            else
                ans.push_back(to_string(nums[j]));
             
            i=j+1;
        }
        
        return ans;
    }
};