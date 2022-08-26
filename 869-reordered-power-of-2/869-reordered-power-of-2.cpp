class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string>st;
        int a=1;
        while(a<=1e9)
        {
            string s=to_string(a);
            sort(begin(s),end(s));
            st.insert(s);
            a*=2;
        }
        string res=to_string(n);
        sort(begin(res),end(res));
        return st.find(res)!=st.end();
    }
};