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
                int val=st.top();
                st.pop();
                if(val==0)
                {
                   val=1;
                }
                else{ 
                    val*=2;
                }
                st.top()+=val;
            }
        }
        
        return st.top();
    }
};