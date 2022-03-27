class Solution {
public:
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       set<pair<int,int>>st;
        int j=0;
        vector<int>ans;
        for(auto i:mat)
        {
            int c=accumulate(begin(i),end(i),0);
            st.insert({c,j++});
        }
        
        for(auto it:st)
        {
            k--;
            ans.push_back(it.second);
            if(k==0) break;
        }
        return ans;
    }
};