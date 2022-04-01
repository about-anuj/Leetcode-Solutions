class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n+2,0),suf(n+2,0);
        
       pre[1]=nums[0];
       suf[n]=nums[n-1];
        
        for(int i=1;i<n;i++)
            pre[i+1]=pre[i]+nums[i];
        
        for(int i=n-2;i>=0 ;i--)
            suf[i+1]=suf[i+2]+nums[i];
        
        for(int i=1;i<=n;i++)
            if(pre[i-1]==suf[i+1])
                return i-1;
          // else if()
        
        return -1;
    }
};