class Solution {
public:
    int prefixCount(vector<string>& words, string p) {
        int ans=0;
        for(auto i:words){
           if(i.rfind(p,0)==0)
                ans++;
        }
        return ans;
    }
};