class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(auto i:grid)
        {
            int sz=i.size()-1;
            while(sz>=0 and i[sz]<0) ans++,sz--;
        }
        return ans;
    }
};