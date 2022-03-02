class Solution {
public:
   
    int numMatchingSubseq(string s, vector<string>& words) {
       int ans=0,j=0;
        unordered_map<char,vector<int>>mp;
        for(auto i :s) mp[i-'a'].push_back(j++);
        
        for(const auto &i:words){
            int x=-1;
            bool find=true;
            for(auto j:i){
                auto it=upper_bound(mp[j-'a'].begin(),mp[j-'a'].end(),x);
                if(it==mp[j-'a'].end()){
                    find=false;
                    break;
                }
                
                x=*it;
            }
            if(find)
                ans++;
        }
        return ans;
    }
};