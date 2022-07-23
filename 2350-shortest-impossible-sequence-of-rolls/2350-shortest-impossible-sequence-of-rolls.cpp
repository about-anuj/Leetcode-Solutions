class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<rolls.size();){
            while(i<rolls.size() and mp.size()<k){
                mp[rolls[i]]++;
                i++;
            }
            if(mp.size()==k)
                ans++;
            mp.clear();
        }
        return ans+1;
    }
};