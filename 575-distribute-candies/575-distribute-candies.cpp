class Solution {
public:
    int distributeCandies(vector<int>& candy) {
        unordered_map<int,int>mp;
        int n=candy.size()/2;
        
        for(auto i:candy){
            mp[i]++;
           if(mp.size()>=n)
               return n;
            
        }
        return mp.size();
    }
};