class Solution {
public:
    int eval(int a,int b,string op){
        if(op=="+") return a+b;
        if(op=="-") return a-b;
        if(op=="/") return a/b;
        return a*b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(auto i:tokens)
        {
            if(i=="+" or i=="-" or i=="/" or i=="*")
            {
                int a=stoi(st.top()); st.pop();
                int b=stoi(st.top()); st.pop();
                string s=to_string(eval(b,a,i));
                st.push(s);
            }
            else
                st.push(i);
        }
        return stoi(st.top());
    }
};