class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       vector<int>v=nums;
        int fst=-1,scnd;
        sort(begin(v),end(v));
        for(int i=0;i<nums.size();i++)
        {
            if(v[i]!=nums[i])
            {
                if(fst==-1) fst=i;
                scnd=i;
            }
        }
        if(fst==-1) return 0;
        return scnd-fst+1;
    }
};