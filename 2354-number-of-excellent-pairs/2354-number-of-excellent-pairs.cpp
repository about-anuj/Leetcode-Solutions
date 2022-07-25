class Solution {
public:
    typedef long long ll;
    int setbits(int n){
        int cnt = 0;
        while(n){
            cnt += (n%2);
            n /= 2;
        }
        return cnt;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> v;
        ll ans=0;
        for(auto& i: s){
            int x = setbits(i);
            v.push_back(x);
        }
        sort(begin(v),end(v));
        for(auto i:v){
            auto it=lower_bound(begin(v),end(v),k-i);
            ans+=(v.end()-it);
        }
        return ans;
    }
};