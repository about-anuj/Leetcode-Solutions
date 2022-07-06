class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>v;
        for(auto i:nums){
            if(v.size()==0) {v.push_back(i); continue;}
            auto it=lower_bound(begin(v),end(v),i)-begin(v);
            if(it==v.size())
                v.push_back(i);
            else
                v[it]=i;
            
        }
        return (int)v.size()>=3;
    }
};