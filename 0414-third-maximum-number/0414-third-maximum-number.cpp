class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>st;
        for(auto i:nums) st.insert(i);
        
        int n=st.size();
        if(st.size()<3) return *st.rbegin();
        
        // cout<<"o";
        for(int i=0;i<2;i++)
          st.erase(*st.rbegin());
        
        return *st.rbegin();
    }
};