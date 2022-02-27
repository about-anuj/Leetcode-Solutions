class Solution {
public:
    int minSteps(string s, string t) {
        int a[26]={0},b[26]={0};
        int ans=0;
        for(auto i:s) a[i-'a']++;
        for(auto i:t) b[i-'a']++;
        
        for(int i=0;i<26;i++)
        ans+=abs(a[i]-b[i]);
            
        return ans;
    }
    
};