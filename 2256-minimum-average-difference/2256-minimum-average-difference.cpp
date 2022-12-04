class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size(),ans=INT_MAX,res;
        vector<long long>pre(n,0),suf(n,0);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--) suf[i]=nums[i]+suf[i+1];
        for(int i=0;i<n;i++)
        {
            int a1=pre[i]/(i+1),a2=0;
            
            if(i<n-1)
            a2=suf[i+1]/(n-i-1);
            int cur=abs(a1-a2);
            if(ans>cur)
            {
                ans=cur;
                res=i;
            }
        }
        return res;
    }
};