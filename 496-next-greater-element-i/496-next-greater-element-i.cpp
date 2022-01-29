class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size(),c=0;
        vector<int>dp(n,-1),ans(nums1.size(),0);
        dp[n-1]=-1;
        stack<int>st;
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() and nums2[i]>st.top())
                st.pop();
            
            if(!st.empty())
                dp[i]=st.top();
            
            st.push(nums2[i]);
        }
        //for(auto i:dp) cout<<i<<" ";
        for(auto i:nums1)
        {
            auto it=find(begin(nums2),end(nums2),i)-begin(nums2);
            ans[c++]=dp[it];
        }
        return ans;
    }
};