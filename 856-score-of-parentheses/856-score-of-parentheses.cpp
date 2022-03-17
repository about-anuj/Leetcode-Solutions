class Solution {
public:
    int scoreOfParentheses(string s) {
       stack<int>st;
        int c=0;
        st.push(0);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(0);
                //c=0;
            }
            else
            {
                if(st.top()==0)
                {
                    st.pop();
                    int val=st.top()+1;
                    st.pop();
                    st.push(val);
                  //  c=1;
                }
                else{
                    int val=2*st.top();
                    st.pop();
                    val+=st.top();
                    st.pop();
                    st.push(val);
                   // st.top()+=2*val;
                }
            }
        }
        
        return st.top();
    }
};