class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int c=0,ans=0,j=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(auto i:nums)
        {
           if(i==1) c++;
            else
                c--;
            
            if(mp.count(c))
                ans=max(ans,j-mp[c]);
            else
                mp[c]=j;
            
            j++;
        }
        
        return ans;
    }
};