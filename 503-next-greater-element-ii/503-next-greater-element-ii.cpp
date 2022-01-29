class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(2*n,-1),dp(n,-1);
        int mx1=max_element(begin(nums),end(nums))-begin(nums);
        
        stack<int>st;
        for(int i=0;i<n;i++)
            nums.push_back(nums[i]);
        
        //we will start from maximum position and from there w'll iterate reverse
        int mx2=mx1+n;
        st.push(nums[mx2]);
        for(int i=mx2-1;i>mx1;i--)
        {
          while(st.size()>0 and nums[i]>=st.top()) st.pop();
            
            if(!st.empty())
                ans[i]=st.top();
            
            st.push(nums[i]);
        }
        int j=mx1;
        for(int i=mx1;i<n;i++) dp[j++]=ans[i];
         j=0;
        for(int i=n;i<mx2;i++) dp[j++]=ans[i];
        return dp;
    }
};