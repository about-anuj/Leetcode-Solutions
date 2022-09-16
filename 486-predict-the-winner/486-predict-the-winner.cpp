class Solution {
public:
    bool calc(vector<int>&nums,int i,int j,bool p1,bool p2,int s1,int s2)
    {
        if(i>j) return s1>=s2;
       
        if(p1)
            return calc(nums,i+1,j,0,1,s1+nums[i],s2) or calc(nums,i,j-1,0,1,s1+nums[j],s2);
       
        
        //if b wins then function will return false
            return calc(nums,i+1,j,1,0,s1,s2+nums[i]) and calc(nums,i,j-1,1,0,s1,s2+nums[j]);
        
        // return p_1 or p_2;
    }
    bool PredictTheWinner(vector<int>& nums) {
        return calc(nums,0,nums.size()-1,true,false,0,0);
    }
};