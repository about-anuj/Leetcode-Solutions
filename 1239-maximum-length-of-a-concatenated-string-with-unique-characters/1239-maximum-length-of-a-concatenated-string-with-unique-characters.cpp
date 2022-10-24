class Solution {
public:
    int ans=0;
    bool unic(string& s)
    {
        unordered_set<char>st;
        st.clear();
        for(auto i:s)
        {
            if(st.find(i)!=st.end()) 
                return 0;
            
            st.insert(i);
        }
        
        return 1;
    }
    void calc(int i,vector<string>&arr,string s)
    {
        if(!unic(s)) return;
        ans=max(ans,(int)s.size());
        if(i>=arr.size()) return;
        calc(i+1,arr,s+arr[i]);
        calc(i+1,arr,s);
    }
    int maxLength(vector<string>& arr) {
        for(int i=0;i<arr.size();i++)
         calc(i,arr,""); 
        return ans;
    }
};