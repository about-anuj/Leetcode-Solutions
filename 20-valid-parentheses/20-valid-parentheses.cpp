class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            char x=s[i];
            if(!st.empty() and ((x==')' and st.top()=='(') or  (x==']' and st.top()=='[') or (x=='}' and st.top()=='{')))
                st.pop();
            else
            st.push(s[i]);
        }
        return st.size()>0?0:1;
    }
};