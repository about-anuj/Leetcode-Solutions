class Solution {
public:
    
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
    unordered_map<int,int>mp;
        int j=0;
        for(auto i:nums)
            mp[i]=j++;
        
        for(auto i:operations)
        {
            nums[mp[i[0]]]=i[1];
            mp[i[1]]=mp[i[0]]; 
        }
        return nums;
        
      //  unordered_map<int,int> store;
    //for(int i=0;i<A.size();i++) store[A[i]]=i;
    // for(auto i:op){
    //     A[store[i[0]]]= i[1];           //replace value to its index
    //     store[i[1]]= store[i[0]];       //update new value with its index
    // }
    // return A;
    }
};