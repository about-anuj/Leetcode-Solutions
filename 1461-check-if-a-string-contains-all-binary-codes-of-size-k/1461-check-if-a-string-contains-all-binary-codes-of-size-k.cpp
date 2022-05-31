class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int ans=pow(2,k);
        unordered_set<string>st;
        int n=s.size();
        for(int i=0;i<=n-k;i++)
        {
           // string temp=;
            st.insert(s.substr(i,k));
        }
        return st.size()==ans;
    }
};