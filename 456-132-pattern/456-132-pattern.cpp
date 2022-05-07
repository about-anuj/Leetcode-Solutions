class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n=nums.size();
        if(n<3) return 0;
        
        stack<int>st;
        st.push(nums[n-1]);
        int third=INT_MIN;
       for(int i=n-1;i>=0;i--)
       {
           if(nums[i]<third) return 1;
           while(!st.empty() and st.top()<nums[i]){
               third=st.top();
               st.pop();
           }
           
           st.push(nums[i]);
       }
      return 0;
    }
};