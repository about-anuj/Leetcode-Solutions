class Solution {
public:
    bool validateStackSequences(vector<int>& push, vector<int>& pop) {
        stack<int>st;
        int n=push.size();
        int j=0;
        for(int i=0;i<n;i++)
        {
            st.push(push[i]);
            while(!st.empty() and j<n and st.top()==pop[j])
            {
                st.pop();
                j++;
            }
        }
        return st.size()==0;
    }
};