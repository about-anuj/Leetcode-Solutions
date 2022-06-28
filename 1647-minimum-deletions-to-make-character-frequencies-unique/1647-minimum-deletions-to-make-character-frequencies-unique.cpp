class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int>f1,f2;
        int ans=0;
        for(auto i:s)
            f1[i-'a']++;
        
        for(auto i:f1){
                int j=i.second;
                //iterate till we seen unseen freq
                while(f2.count(j)){
                    j--;
                    ans++;
                }
            if(j!=0)
              f2[j]++;
            }
        
        return ans;
    }
};