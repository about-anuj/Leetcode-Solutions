class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
     vector<int>ans;
        for(auto &i:q)
        {
            int trim=i[1];
            vector<pair<string,int>>temp;
            int ind=0;
            for(auto &j:nums)
                temp.push_back({j.substr(j.size()-trim),ind++});
           
            sort(begin(temp),end(temp));
            
            ans.push_back(temp[i[0]-1].second);
        }
        return ans;
    }
};