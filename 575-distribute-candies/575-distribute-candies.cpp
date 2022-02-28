class Solution {
public:
    int distributeCandies(vector<int>& candy) {
        unordered_map<int,int>mp;
        for(auto i:candy)
            mp[i]++;
        
       int n=candy.size()/2;
        
        if(n<=mp.size())
            return n;
        
        return mp.size();
    }
};