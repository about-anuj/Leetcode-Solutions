class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr=0,n1=0,n2=0;
        for(auto i:nums) xr^=i;
        //right most set bit
        long long rmsb= xr & ~(xr-1);
        for(auto i:nums)
        {
            if(rmsb & i) n1^=i;
            else n2^=i;
        }
        return {(int)n1,(int)n2};
    }
};