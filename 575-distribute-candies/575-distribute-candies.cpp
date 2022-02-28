class Solution {
public:
    int distributeCandies(vector<int>& candy) {
        unordered_set<int>st;
        int n=candy.size()/2;
        
        for(auto i:candy){
            st.insert(i);
           if(st.size()>=n)
               return n;
            
        }
        return st.size();
    }
};